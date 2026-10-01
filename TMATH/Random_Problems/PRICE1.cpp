#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define nmax 1000000
ll a[nmax],n,ma[nmax],f[nmax],ma1[nmax];
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
        ma[1]=a[1];
    for(int i=2;i<=n;i++)
        ma[i]=max(a[i-1],ma[i-1]);
        f[1]=1;
    for(int i=2;i<=n;i++)
    {
        if(a[i]>a[i-1])
            {
                f[i]=f[i-1]+1;
                ma1[i]=max(a[i-1],ma1[i-1]);
            }
        else {
                f[i]=1;
                ma1[i]=a[i];
        }
    }
   for(int i=1;i<=n;i++)
    {
        if(a[i]>ma[i])
            f[i]=i;
        else

    }
    for(int i=1;i<=n;i++)
        cout<<f[i];
}
