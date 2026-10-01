#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define nmax 1000000
ll n,a[nmax],ans,k,kq;
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
        if(ans<=k) kq=mid, r=mid-1;
        else l=mid+1;
    }
    return kq;
}
int main()
{
    freopen("D.inp","r",stdin);
    freopen("D.out","w",stdout);
    cin>>k>>n;
    for(int i=1;i<=n;i++)
    cin>>a[i];
    cout<<chat(1,1e9);

}