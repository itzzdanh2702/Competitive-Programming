#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define nmax 1000000
const ll mod=1e9+7;
ll a[nmax],n,ans,f[nmax],k;
int main()
{
    freopen("DOITIEN.inp","r",stdin);
    freopen("DOITIEN.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    cin>>a[i];
    sort(a+1,a+n+1);
    f[0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=k;j++)
        {
            ll ans=j-a[i];
            if (ans>=0) f[j]=(f[ans]+f[j])%mod;
        }
    }

cout<<f[k];
}
