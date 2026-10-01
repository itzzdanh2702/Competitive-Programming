#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define nmax 1000000
ll n,a[nmax],ans,k;
ll chat(ll l,ll r)
{
   
    while(l<=r)
    {
        ll mid=(l+r)/2;
        ll ans=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]%mid==0) ans+=a[i]/mid;
            else ans+=a[i]/mid+1;
        }
        if(ans<=k) kq=mid, l=mid-1;
        else r=mid+1;
    }
    return kq;
}
int main()
{
    cin>>k>>n;
    for(int i=1;i<=n;i++)
    cin>>a[i];
    cout<<chat(1,1e9);


}