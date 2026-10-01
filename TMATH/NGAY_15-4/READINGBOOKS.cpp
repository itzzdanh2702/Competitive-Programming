#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define pii pair<ll, ll>
const long long MOD = 1000000007;
#define MAXN 1000005
#define oo 1000000000
void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll n, k;
ll a[MAXN];
ll pre[MAXN];
ll ans = -1;
int main()
{
    FAST();
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        ll l = 1, r = i;
        while (l <= r)
        {
            ll mid = (l + r) / 2;
            if (pre[i] - pre[mid - 1] <= k)
            {
                r = mid - 1;
                ans = max(ans, i - mid + 1);
            }
            else
            {
                l = mid + 1;
            }
        }
    }
    cout << ans;
}