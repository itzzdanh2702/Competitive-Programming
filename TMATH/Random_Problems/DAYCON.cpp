#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n, a[100005], s[100005], k, sum = 0,mi=1000000000 ;
ll tong(ll d, ll c, ll x)
{
    ll g, ans = 0 ;
    ll d1 = d;
    while(d <= c)
    {
        g = (d+c)/2;
        if(s[g] - s[d1-1] < x)
        {

            d = g + 1 ;
        }
        else
        {
            ans = g ;
            c = g - 1 ;
        }
    }
    return ans;
}
int main()
{
    cin>>n>>k;
    for(int i = 1 ; i <= n ; i++)
    {
        cin>>a[i];
        s[i] += s[i-1] + a[i];
    }
    if(s[n]<k) cout<<"0";
    else
    {
    for(int i = 1 ; i <= n ; i++)
    {
           if(tong(i,n,k) - i + 1>0)
            mi=min(tong(i,n,k) - i + 1,mi);
    }
    cout<<mi;
    }

}
