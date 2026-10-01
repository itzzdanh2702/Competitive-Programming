#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define nmax 1000000
ll n,f[nmax],a[nmax],dp[1000][1000],k;
bool check;
int main()
{
    freopen("NUMBER2.inp","r",stdin);
    freopen("NUMBER2.out","w",stdout);
    cin>>n>>k;
    f[0]=4;
    f[1]=3;
    f[2]=3;
    for(int i=1;i<=k;i++)
    {
        cin>>a[i];
        if(a[i]!=0) check=true;

    }
    for(int i=1;i<=k;i++)
        f[a[i]%3]--;
    if(check)
    {

    dp[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        if(i!=1)
        {
        dp[0][i]=f[0]*dp[0][i-1]+f[1]*dp[2][i-1]+f[2]*dp[1][i-1];
        dp[1][i]=f[0]*dp[1][i-1]+f[1]*dp[0][i-1]+f[2]*dp[2][i-1];
        dp[2][i]=f[0]*dp[2][i-1]+f[1]*dp[1][i-1]+f[2]*dp[0][i-1];
        }
        else if (i==1)
        {
        dp[0][i]=(f[0]-1)*dp[0][i-1]+f[1]*dp[2][i-1]+f[2]*dp[1][i-1];
        dp[1][i]=(f[0]-1)*dp[1][i-1]+f[1]*dp[0][i-1]+f[2]*dp[2][i-1];
        dp[2][i]=(f[0]-1)*dp[2][i-1]+f[1]*dp[1][i-1]+f[2]*dp[0][i-1];
        }

    }

    cout<<dp[0][n];
    }
    else
    {
    dp[0][0]=1;
    for(int i=1;i<=n;i++)
    {

        dp[0][i]=f[0]*dp[0][i-1]+f[1]*dp[2][i-1]+f[2]*dp[1][i-1];
        dp[1][i]=f[0]*dp[1][i-1]+f[1]*dp[0][i-1]+f[2]*dp[2][i-1];
        dp[2][i]=f[0]*dp[2][i-1]+f[1]*dp[1][i-1]+f[2]*dp[0][i-1];

    }

    cout<<dp[0][n];
    }
}
