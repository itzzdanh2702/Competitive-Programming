#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define nmax 1000001
ll a,b;
bool check[nmax];
vector<ll> v;


int main()
{
    freopen("A.inp","r",stdin);
    freopen("B.out","w",stdout);
    cin>>a>>b;
    memset(check,false,sizeof(check));
    for(ll i=1;i<=709;i++)
    {
        for(ll j=i+1;j<=710;j++)
        {
            check[i*i+j*j]=true;
        }
    }
    
    for(ll i=a;i<=b;i++)
    {
        if(check[i])
        v.push_back(i);
    }
    if(v.size()!=0)
    {
    cout<<v.size()<<endl;
    for(auto x: v)
    {
        cout<<x<<' ';
    }
    }
    else cout<<"-1";
}