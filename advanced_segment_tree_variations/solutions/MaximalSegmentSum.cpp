// DONOT TOUCH DRIVER CODE
#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;
typedef long long ll;
typedef long double ld;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define max3(a, b, c) max(max(a, b), c)
#define max4(a, b, c, d) max(max(a, b), max(c, d))
#define fr(i, n) for (ll i = 0; i < n; i++)
ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}
#include <filesystem>
namespace fs = std::filesystem;
int countTests(const string &folder)
{
    int cnt = 0;

    for (auto &entry : fs::directory_iterator(folder))
    {
        if (entry.path().extension() == ".in")
            cnt++;
    }

    return cnt;
}

template <typename T>
class SegmentTree
{
private:
    vector<T> arr;
    vector<T> tree;
    // T null_value;
    long long n;
    T combine(T a, T b)
    {
        T res;
        res.sum = a.sum + b.sum;
        res.prefix_sum = max(a.prefix_sum, a.sum + b.prefix_sum);
        res.suffix_sum = max(b.suffix_sum, b.sum + a.suffix_sum);
        res.max_sum = max(max(a.max_sum, b.max_sum), a.suffix_sum + b.prefix_sum);
        return res;
    }
    void update_tree(long long idx, T val, long long node, long long left, long long right)
    {
        if (left == right)
        {
            tree[node] = val;
            return;
        }
        long long mid = (left + right) / 2;
        if ((left <= idx) && (idx <= mid))
        {
            update_tree(idx, val, 2 * node + 1, left, mid);
        }
        else if (((mid + 1) <= idx) && (idx <= right))
        {
            update_tree(idx, val, 2 * node + 2, mid + 1, right);
        }
        tree[node] = combine(tree[2 * node + 1], tree[2 * node + 2]);
    }
    T sum_tree(long long L, long long R, long long node, long long left, long long right)
    {
        if ((left == L) && (right == R))
        {
            return tree[node];
        }
        long long mid = (left + right) / 2; // 0
        if ((max(L, left) <= min(mid, R)) && (max(mid + 1, L) <= min(R, right)))
        {
            T leftsum = sum_tree(max(L, left), min(mid, R), 2 * node + 1, left, mid);
            T rightsum = sum_tree(max(mid + 1, L), min(R, right), 2 * node + 2, mid + 1, right);
            return combine(leftsum, rightsum);
        }
        else if (max(L, left) <= min(mid, R))
        {
            return sum_tree(max(L, left), min(mid, R), 2 * node + 1, left, mid);
        }
        else
        {
            return sum_tree(max(mid + 1, L), min(R, right), 2 * node + 2, mid + 1, right);
        }
    }
    void build(long long node, long long left, long long right)
    {
        if (left == right)
        {
            tree[node] = arr[left];
            return;
        }
        long long mid = (left + right) / 2;
        build(2 * node + 1, left, mid);
        build(2 * node + 2, mid + 1, right);
        tree[node] = combine(tree[2 * node + 1], tree[2 * node + 2]);
    }

public:
    SegmentTree(vector<T> v)
    {
        arr = v;
        n = arr.size();
        tree.resize(4 * n);
        build(0, 0, n - 1);
    }
    void update(long long idx, T val)
    {
        update_tree(idx, val, 0, 0, n - 1);
    }
    T query(long long L, long long R)
    {
        return sum_tree(L, R, 0, 0, n - 1);
    }
};
struct Node
{
    ll sum;
    ll prefix_sum;
    ll suffix_sum;
    ll max_sum;
};
const ll ninf = -1e5;
void solve(istream &in, ostream &out)
{
    ll n;
    in >> n;
    vector<Node> v(n);
    for (auto &i : v)
    {
        in >> i.sum;
        i.prefix_sum = i.suffix_sum = i.max_sum = i.sum;
    }
    SegmentTree<Node> st(v);
    ll q;
    in >> q;
    while (q--)
    {
        ll ty;
        in >> ty;
        if (ty == 1)
        {
            ll l, r;
            in >> l >> r;
            l--;
            r--;
            out << st.query(l, r).max_sum << "\n";
        }
        else
        {
            ll idx, val;
            in >> idx >> val;
            idx--;
            st.update(idx, {val, val, val, val});
        }
    }
}

string normalize(const string &s)
{
    string t;
    for (char c : s)
        if (c != '\r')
            t += c; // remove CR (windows safety)
    return t;
}
string trim(const string &s)
{
    auto start = find_if_not(s.begin(), s.end(), [](unsigned char ch)
                             { return isspace(ch); });

    auto end = find_if_not(s.rbegin(), s.rend(), [](unsigned char ch)
                           { return isspace(ch); })
                   .base();

    if (start >= end)
        return "";

    return string(start, end);
}
int main()
{
    int tests = countTests("tests");

    for (int i = 0; i < tests; ++i)
    {
        string inFile = "tests/" + to_string(i) + ".in";
        string outFile = "tests/" + to_string(i) + ".out";

        ifstream fin(inFile);
        ifstream fout(outFile);

        if (!fin || !fout)
        {
            cout << "Missing file for test " << i << "\n";
            continue;
        }

        ostringstream myOutput;

        // ⏱ START TIMER
        auto start = high_resolution_clock::now();

        solve(fin, myOutput);

        // ⏱ END TIMER
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);

        string expected((istreambuf_iterator<char>(fout)), {});
        string actual = myOutput.str();

        expected = normalize(expected);
        actual = normalize(actual);

        expected = trim(expected);
        actual = trim(actual);

        if (expected == actual)
        {
            cout << "Test " << i << ": PASS";
        }
        else
        {
            cout << "Test " << i << ": FAIL\n";
            cout << "Expected:\n"
                 << expected
                 << "\nGot:\n"
                 << actual << "\n";
        }

        // ⏱ Print execution time
        cout << " | Time: " << duration.count() << " microseconds";
        cout << " (" << duration.count() / 1000.0 << " ms)";
        cout << "\n";
    }
}
