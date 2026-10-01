#include <bits/stdc++.h>
using namespace std;
#define ll long long 
const long long MOD = 1000000007;
#define MAXN 1000005
#define oo 1000000000
void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll n;   
ll a[1005][1005];
ll dp[1005][1005];

int main()
{
    cin >> n;
    for(int i = 1 ; i <= n ; ++i)
    {
        for(int j = 1 ; j <= i ; ++j)
        {
            cin >> a[i][j];
        }
    }
    for(int i = 1 ; i <= n ; ++i)
    {
        for(int j = 1 ; j <= i ; ++j)
        {
            dp[i][j] = 0;
        }
    }
    for(int i = 1 ; i <= n ; ++i)
    {
        for(int j = 1 ; j <= i ; ++j)
        {
            dp[i][j] = max(dp[i - 1][j - 1],dp[i - 1][j]) + a[i][j];
        }
    }
    ll ma = -1;
    for(int i = 1 ; i <= n ; ++i)
    {
        ma = max(ma,dp[n][i]);
    }
    cout << ma;
}