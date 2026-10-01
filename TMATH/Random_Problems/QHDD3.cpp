#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nmax 1000000
long long a[nmax], n,s=0,j=-1e9,l[nmax],r[nmax],ma=-1e9;
int main()
{

cin>>n;
for(long long i=1;i<=n;i++)
    cin>>a[i];
    l[1]=a[1];
for(int i=2;i<=n;i++)
{
    l[i]=max(l[i-1],a[i-1]);
}
l[n]=a[n];
for(int i=n-1;i>=1;i--)
{
    r[i]=min(r[i+1],a[i+1]);
}
//for(int i=1;i<=n;i++)
    //cout<<l[i-1]<<" ";
    for(int i=1;i<=n;i++)
        ma=max(ma,l[i-1]+a[i]-r[i+1]);
        cout<<ma;

}
