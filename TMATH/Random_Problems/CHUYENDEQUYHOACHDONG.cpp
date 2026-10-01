#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define nmax 1000000
ll n,a[nmax],s[nmax],k;
int tong(ll l,ll r, ll x)
{
    ll l1=l,ans;
    while(l<=r)
    {
        ll mid=(l+r)/2;
        if(s[mid]-s[l1-1    ]<=x)
        {
            ans=mid;
            l++;
        }
        else
            r=r-1;

    }
    return ans;
}
int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        s[i]=s[i-1]+a[i];
        ll sum=0;
    for(int i=1;i<=n;i++)
    {
        if(tong(i,n,k)-i>=0)
            sum+=tong(i,n,k)-i+1;
    }
    cout<<sum;
}
