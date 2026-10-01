#include<bits/stdc++.h>
#define str string
#define nmax 1000005
#define ll long long

using namespace std;

ll n,q,a[nmax],f[nmax],g[nmax],v[nmax],ma=-1e18;

int main(){

    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>a[i];
    ll dem1=0,dem2=0,dem3=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]==1) dem1++;
        else if(a[i]==2) dem2++;
        else dem3++;
        f[i]=dem1;
        g[i]=dem2;
        v[i]=dem3;
    }
    while(q--)
    {
        ll a,b;
        cin>>a>>b;
        cout << f[b]-f[a-1] << " ";
        cout << g[b]-g[a-1] << " ";
        cout << v[b]-v[a-1] << '\n';
    }
}
