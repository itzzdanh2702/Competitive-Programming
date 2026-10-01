#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define nmax 1000000
ll a,n,dp[3][nmax],f[3];
int main()
{
    cin>>n;
    for(int i=1;i<=3;i++)
    {
        cin>>a;
        f[a%3]++;
    }
    dp[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        dp[0][i]=f[0]*dp[0][i-1]+f[1]*dp[2][i-1]+f[2]*dp[1][i-1];
        dp[1][i]=f[0]*dp[1][i-1]+f[1]*dp[0][i-1]+f[2]*dp[2][i-1];
        dp[2][i]=f[0]*dp[2][i-1]+f[1]*dp[1][i-1]+f[2]*dp[0][i-1];
    }
    cout<<dp[0][n];
}
