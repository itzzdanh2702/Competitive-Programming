#include<bits/stdc++.h>

using namespace std;

#define ll long long
const int MAXW = 1e5 + 1;
const int MAXN = 101;

void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int n,w;
int kl[MAXN],v[MAXN];
ll dp[MAXN][MAXW];

int main()
{
    FAST();
   // freopen("Knapsack1.inp","r",stdin);
   // freopen("Knapsack1.out","w",stdout);
    cin >> n >> w;
    for(int i = 1 ; i <= n ; ++i)
        cin >> kl[i] >> v[i];
    memset(dp,0,sizeof(dp));
    for(int i = 1 ; i <= n ; ++i)
    {
        for(int j = 1 ; j <= w ; ++j)
        {
            dp[i][j] = dp[i - 1][j];
            if(j - kl[i] >= 0)
                dp[i][j] = max(dp[i][j],dp[i - 1][j - kl[i]] + v[i]);
        }
    }
    cout << dp[n][w];
    //cout << 1;
}
