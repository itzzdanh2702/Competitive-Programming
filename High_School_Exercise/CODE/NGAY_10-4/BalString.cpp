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
string S;
map<ll, ll> mp, mp1;
ll n;
ll dp[MAXN][2];
ll ans[MAXN];
ll kq = 0;
ll ma = -1;

int main()
{
    FAST();
    //freopen("BALSTRING.INP", "r", stdin);
    //freopen("BALSTRING.OUT", "w", stdout);
    cin >> n;
    cin >> S;
    S = " " + S;
    for (int i = 1; i <= n; ++i)
    {
        if (S[i] == '0')
        {
            dp[i][0] = dp[i - 1][0] + 1;
            dp[i][1] = dp[i - 1][1];
        }
        else
        {
            dp[i][1] = dp[i - 1][1] + 1;
            dp[i][0] = dp[i - 1][0];
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        ans[i] = dp[i][0] - dp[i][1];
    }
    for (int i = 1; i <= n; ++i)
    {
        if (mp1[ans[i]] == 0)
        {
            mp[ans[i]] = i; // pos
            mp1[ans[i]] = 1;
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        if (ans[i] == 0)
        {
            ma = max(ma, i * 1LL);
        }
        else
        {
            ma = max(ma, i - mp[ans[i]]);
            cout << i << " " << mp[ans[i]] << '\n';
        }
    }
    cout << ma;
}
