#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll m,n,k;
ll BS(ll l,ll r,ll x,ll i)
{
    ll dem=0;
    if (l>r) return dem;
    else
    {
        ll mid=(l+r)/2;
        if (mid*i<x)
        {
            dem+=mid-l+1;
            ll t=BS(mid+1,r,x,i);
            dem+=t;
        }
        else
        {
            ll t=BS(l,mid-1,x,i);
            dem+=t;
        }
    }
    return dem;
}
ll demsn(ll x)
{
    ll sum=0;
    for (int i=1;i<=m;i++)
    {
        ll t=BS(1,n,x,i);
        sum+=t;
    }
    return sum;
}
ll binsearch(ll l, ll r, ll x)
{
    ll res=0;
    while(l<=r)
    {
        ll mid=(l+r)/2;
        ll cp=demsn(mid);
        if (cp<x)
        {
            res=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
    cin>>m>>n>>k;
    cout<<binsearch(1,m*n,k);
}