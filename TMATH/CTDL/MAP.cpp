#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define nmax 1000000
string S;
map<ll,ll> mp;
ll a[nmax],b[nmax],ans,n,k;
int main()
{
    cin>>n>>k;
    cin>>S;
    S=""+S;
    for(int i=1;i<=n;i++)
    {
        a[i]=a[i-1];
        b[i]=b[i-1];
        if(S[i]=='O') a[i]++;
        else b[i]++;
    }
    for(int i=n;i>=1;i--)
    {
     mp[a[i]-k*b[i]]=i;
    }
    for(int i=1;i<=n;i++)
    {
     ans=max(ans,i-mp[a[i]-k*b[i]]);
    }
    cout<<ans;
}