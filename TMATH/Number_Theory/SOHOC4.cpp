#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a,k=1,nmax=1e9+7;
ll somu(ll a,ll n)
{
    if (n==1) return a%nmax;
    if (n==0) return 1;
    if (a==1) return 1;
    if (a==0) return 0;
    if (n%2==0)
    {
        ll t=somu(a,n/2)%nmax;
        return (t*t)%nmax;
    }
    else
    {
        ll t=somu(a,n/2)%nmax;
        return (a%nmax)*(t*t)%nmax;
    }
}
ll mu(ll a,ll n)
{
    ll P;
    if (n==1) return a;
    if (n%2==0)
    {
        ll t=mu(a,n/2);
        P=(t+t*somu(a,n/2))%nmax;
    }
    else
    {
        ll t=mu(a,n-1);
        P=(t+somu(a,n))%nmax;
    }
    return P;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>a>>n;
    cout<<(mu(a,n)+1)%nmax;
}
