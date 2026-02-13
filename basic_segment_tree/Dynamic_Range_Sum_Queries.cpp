
#include <bits/stdc++.h>
#include "Generalized_Segment_Tree.h"
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
int main()
{
    fastio;
    ll n, q;
    cin >> n >> q;
    vector<ll> v(n);
    for (auto &i : v)
        cin >> i;
    SegmentTree<ll> st(v, 0);
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