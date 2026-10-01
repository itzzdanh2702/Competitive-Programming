#include <bits/stdc++.h>
using namespace std;
#define ll long long
const long long MOD = 1000000007;
#define fi first
#define se second
#define pii pair<ll, ll>
#define MAXN 1000005
#define oo 1000000000
pii a[MAXN];
void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll n, w, l;
unsigned ll ans = 0;

int main()
{
    FAST();
    freopen("TREE.inp", "r", stdin);
    freopen("TREE.out", "w", stdout);
    cin >> n >> w >> l;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i].fi >> a[i].se;
    }
    ll left = 0, right = 1e18;
    while (left <= right)
    {
        unsigned ll kq = 0;
        ll mid = (left + right) / 2;
        for (int i = 1; i <= n; ++i)
        {
            if(a[i].fi + mid * a[i].se >= l)
            {
                kq += a[i].fi + mid * a[i].se;
            }
        }
        if (kq >= w)
        {
            right = mid - 1;
            ans = mid;
        }
        else
        {
            left = mid + 1;
        }
    }
    cout << ans;
}