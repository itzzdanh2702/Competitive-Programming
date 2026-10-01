#include<bits/stdc++.h>
#define ll long long
#define nmax 1000000
#define mod 1000000007
using namespace std;
ll n,k,f[nmax+5];
int main()
{
    cin>>n>>k;
    f[0]=1;
    for(ll i=1;i<=n;i++)
    {
       for(ll j=max(0LL,i-k);j<=i-1;j++)
            f[i]=(f[i]+f[j])%mod;
    }
    cout<<f[n];
}
