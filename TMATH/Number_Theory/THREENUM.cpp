#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define nmax 1000000
#define fi first
#define se second
ll a[nmax],n,dem=0,k,S[nmax],x;
pair<ll,ll> b;
int BS(ll a[],ll l,ll r,ll x)
{
    if(l>r) return 0;
    else
    {
        ll mid=(l+r)/2;
        if(a[mid]==x)
            return mid;
        else if(a[mid]>x)
            BS(a,l,mid-1,x);
        else BS(a,mid+1,r,x);
    }
}
int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            b.fi=a[i];
            b.se=i;
        }
        sort(a+1,a+n+1);
    for(int i=1;i<=n-1;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            dem++;
            S[dem]=a[i]+a[j];
        }
    }
    for(int i=1;i<=dem;i++)
    {
        x=k-S[i];
        cout<< BS( a,1,n, x)<<endl;
    }

}
