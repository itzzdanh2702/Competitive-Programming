#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
#define ll long long
using namespace std;
ll n,k,a[1000006];
ll ans;
map<ll,ll> f;
int main()
{
    fast
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        f[a[i]]++;
    }
    for(int i=1;i<=n;i++) ans+=f[k-a[i]];
   ans/=2;
   cout<<ans;
}
