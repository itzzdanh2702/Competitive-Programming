#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define nmax 1000000
#define mod 1000000007
ll a[nmax],n,ma,dp[nmax],t;
int main()
{
    freopen("DOMINO4.inp","r",stdin);
    freopen("DOMINO4.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>a[i];
        ma=max(ma,a[i]);
    }
    dp[1]=1;
    dp[2]=1;
    dp[3]=1;
    dp[4]=2;
    for(int i=5;i<=ma;i++)
    {
       dp[i]=(dp[i-4]+dp[i-1])%mod;
    }
    for(int i=1;i<=t;i++)
    {
        cout<<dp[a[i]]<<endl;
    }
}