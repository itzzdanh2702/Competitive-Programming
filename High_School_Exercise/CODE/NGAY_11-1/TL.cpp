#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define nmax 1000000
#define fi first
#define se second
ll n, dp[nmax + 5], ans = -1e18;
pair <ll,ll> a[nmax];
int main()
{
    freopen("TL.inp","r",stdin);
    freopen("TL.out","w",stdout);
    cin >> n;
    for (int i = 1 ; i <= n ; i++)
        cin >> a[i].fi >> a[i].se;
    sort(a + 1 , a + n + 1);
    for (int i = 1 ; i <= n ; i++)
        dp[i] = max(dp[i - 1] + a[i].se, a[i].se + a[i].fi);
    for (int i = 1 ; i <= n ; i++)
        ans = max(ans, dp[i] - a[i].fi);
    cout << ans;
    return 0;
}