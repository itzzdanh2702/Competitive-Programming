#include<bits/stdc++.h>
using namespace std ;
#define ll long long 

ll const nmax=1005;
ll const mod=1e9+7;

ll n,x,dp[nmax][100005]={0},a[nmax],b[nmax];
int main ()
{
    freopen("BOOK.inp","r",stdin);
    freopen("BOOK.out","w",stdout) ;
    ios_base::sync_with_stdio(0) ;
    cin.tie(0) , cout.tie(0) ;
    cin>>n>>x;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=x;j++)
        {
            if(a[i]<=j)
                dp[i][j]=max(dp[i-1][j-a[i]]+b[i],dp[i-1][j]);
    	    else dp[i][j]=dp[i-1][j];
        }
    }
    cout<<dp[n][x];
    return 0;
}