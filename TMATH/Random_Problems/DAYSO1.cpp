#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define nmax 1000000
#define mod 1000000007
ll a[nmax],n,b[nmax],dem=0,S=0;
int main()
{
    cin>>n;
    a[0]=a[1]=1;
    for(int i=2;i<=n;i++)
        a[i]=(a[i-1]%mod+a[i-2]%mod)%mod;
    cout<<a[n]%mod;
}
