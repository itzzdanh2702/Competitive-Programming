#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define pii pair<ll, ll>
const long long MOD = 1000000007;
#define MAXN 2005
#define oo 1000000000
void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int n;
int a[MAXN];
int dp1[MAXN];
int dp2[MAXN];

int main()
{
    FAST();
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    dp1[1] = 0;
    for (int i = 2; i <= n; ++i)
    {
        for (int j = 1; j <= i - 1; ++j)
        {
            dp1[i] = max(dp1[i], __gcd(a[i], a[j]));
        }
    }
    dp1[n] = 0;
    for (int i = n - 1; i >= 1; --i)
    {
        for(int j = i + 1 ; j <= n ; ++j)
        {
            dp2[i] = max(dp2[i],__gcd(a[i],a[j]));
        }
    }
    int ans = -1;
    for(int i = 1 ; i <= n ; ++i)
    {
        for(int j = i + 1 ; j <= n ; ++j)
        {
            ans = max(ans,dp1[i] + dp2[j]);
        }
    }
    cout << ans;
}