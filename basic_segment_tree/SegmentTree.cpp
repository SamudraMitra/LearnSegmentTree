// DONOT TOUCH DRIVER CODE
#include <bits/stdc++.h>
#include "SegmentTree.h"
#include <chrono>
using namespace std;
using namespace std::chrono;
using namespace std;
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
void solve(istream &in, ostream &out)
{
    ll n, q;
    in >> n >> q;
    vector<ll> v(n);
    for (auto &i : v)
        in >> i;
    SegmentTree st(v);
    while (q--)
    {
        ll ty, a, b;
        in >> ty >> a >> b;
        a--;
        b--;
        if (ty == 1)
        {
            b++;
            st.update(a, b);
        }
        else
        {
            ll res = st.query(a, b);
            out << res << "\n";
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

    for (int i = 1; i <= tests; ++i)
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
