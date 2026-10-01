#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define nmax 1000000
ll a[nmax],n,b[nmax],t,u[nmax],x[nmax],k,res=0,l,r;
bool check(ll x)
{
    ll   base=1;
    for(ll i=1;i<x;++i)
    {
        if(a[i]+base>a[x]+n) return 0;
        else base++;
    }
    return 1;
}
int main()
{
    for(int i=1;i<=n;i++)
        cin>>a[i];
        sort(a+1,a+n+1,greater<ll>());
    l=1,r=n;
        while(l<=r)
        {
            ll mid=(l+r)/2;
            if(check(mid)) {
                    res=mid;
                    l=mid+1;
            }
            else r=mid-1;
        }
    cout<<res;

}
