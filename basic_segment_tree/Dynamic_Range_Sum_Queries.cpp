
#include <bits/stdc++.h>
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
class SegmentTree
{
private:
    vector<ll> arr;
    vector<ll> tree;
    ll null_value;
    ll n;
    ll combine(ll a, ll b)
    {
        return a + b;
    }
    void update_tree(ll idx, ll val, ll node, ll left, ll right)
    {
        if (left == right)
        {
            tree[node] = val;
            return;
        }
        ll mid = (left + right) / 2;
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
    ll sum_tree(ll L, ll R, ll node, ll left, ll right)
    {
        if (L > R)
            return null_value;
        if ((left == L) && (right == R))
        {
            return tree[node];
        }
        ll mid = (left + right) / 2;
        ll leftsum = sum_tree(max(L, left), min(mid, R), 2 * node + 1, left, mid);
        ll rightsum = sum_tree(max(mid + 1, L), min(R, right), 2 * node + 2, mid + 1, right);
        return combine(leftsum, rightsum);
    }
    void build(ll node, ll left, ll right)
    {
        if (left == right)
        {
            tree[node] = arr[left];
            return;
        }
        ll mid = (left + right) / 2;
        build(2 * node + 1, left, mid);
        build(2 * node + 2, mid + 1, right);
        tree[node] = combine(tree[2 * node + 1], tree[2 * node + 2]);
    }

public:
    SegmentTree(vector<ll> v, ll nv)
    {
        arr = v;
        n = arr.size();
        null_value = nv;
        tree.resize(4 * n, nv);
        build(0, 0, n - 1);
    }
    void update(ll idx, ll val)
    {
        update_tree(idx, val, 0, 0, n - 1);
    }
    ll sum(ll L, ll R)
    {
        return sum_tree(L, R, 0, 0, n - 1);
    }
};
int main()
{
    fastio;
    ll n, q;
    cin >> n >> q;
    vector<ll> v(n);
    for (auto &i : v)
        cin >> i;
    SegmentTree st(v, 0);
    while (q--)
    {
        ll ty, a, b;
        cin >> ty >> a >> b;
        a--;
        b--;
        if (ty == 1)
        {
            b++;
            st.update(a, b);
        }
        else
        {
            ll res = st.sum(a, b);
            cout << res << "\n";
        }
    }
}