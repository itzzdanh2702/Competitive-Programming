#include<bits/stdc++.h>
#define ll long long
#define nmax 100000005
#define str string
#define chr char
#define mod 1000000007
#define modd 1073741824

using namespace std;

ll mu(ll a,ll n)
{
    if(n==0) return 1;
    ll tam=mu(a,n/2);
    tam=(tam*tam)%mod;
    if(n%2!=0) tam=(tam*a)%mod;
    return tam%mod;
}

ll m,b[1000005],c[1000005],dem=0,r,sh,tong,p=0,l;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>m;
    tong=mu(10,m)%mod;
    sh=mu(9,m)%mod;
    l=mu(8,m)%mod;
    r=(tong-(2*sh)%mod+l)%mod;
    cout<<(r%mod+mod)%mod;
}
