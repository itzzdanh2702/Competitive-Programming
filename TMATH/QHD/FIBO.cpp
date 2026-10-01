#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define nmax 10000000
#define nmaxx 1e9
unsigned long long n,dem=0,f[nmax];

int main()
{
    freopen("FIBO.inp","r",stdin);
    freopen("FIBO.out","w",stdout);
    while(cin>>n)
    {
    f[1]=f[2]=1;
    while (n>0)
    {
        ll i=2;
        while(f[i]<=n)
    {
        i++;
        f[i]=f[i-1]+f[i-2];

    }
    cout<<f[i-1]<<" ";
    n=n-f[i-1];
    }
    cout<<endl;
    }

}
