#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define nmax 1000000
ll a[nmax],b[nmax],n,f[nmax],g[nmax],pos[nmax],pos1[nmax],q[nmax];
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        f[a[i]]=i;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
        g[b[i]]=i;
    }
    for(int i=1;i<=n;i++)
    {
        if(f[i]>g[i])
        pos[i]=f[i]-g[i];
        else
        pos[i]=f[i]+n-g[i];
    }
    sort(pos+1,pos+n+1);
    ll dem=1,dem1=0;
    pos[n+1]=-1;
    for(int i=2;i<=n+1;i++)
    {
        if(pos[i]==pos[i-1])
            dem++;
        else
        {
            dem1++;
            pos1[dem1]=dem;
           // q[pos1[dem1]]=pos[i-1];
            dem=1;

        }
    }

    sort(pos1+1,pos1+dem1+1,greater<ll>());
   cout<<pos1[1];
}
