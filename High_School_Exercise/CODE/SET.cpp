#include <bits/stdc++.h>
using namespace std;

int n, m, x[5005], y[5005];
long long dp[5005][5005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i=1; i<=n; i++) cin >> x[i] >> y[i];
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            dp[i][j] = min({dp[i][j], dp[i-1][j], dp[i][j-1]});
            if(j >= y[i]) dp[i][j] = min(dp[i][j], dp[i-1][j-y[i]]+x[i]);
        }
    }
    cout << dp[n][m];
}
for(int i=1;i<=n;i++)
{
 for(int j=1;j<=min(i,x);j++)
{
    dp[i][j]=dp[i-1][j]*j+dp[i-1][j-1];
}
}
dp[4][2]=dp[3][2]*2+dp[3][1];
12 3
13 2
23 1


dp[4][3]=dp[3][3]*3+dp[3][2];
        =1*3+3=6
        12 3 4
        13 2 4
        14 2 3
        23 1 4
        24 1 3
        34 1 2
10 5
dp[10][5]=dp[9][5]*5+dp[9][4];

