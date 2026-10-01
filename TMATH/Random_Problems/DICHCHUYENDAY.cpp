#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define nmax 1000000
ll n,dem1=0;
ll a[nmax],b[nmax],P,Q,dem=0;
string p;
int main()
{
 cin>>n;
 for(int i=1;i<=n;i++)
    cin>>a[i];
for(int i=1;i<=n;i++)
    cin>>b[i];
 for(int i=1;i<=n;i++)
    if(a[i]==b[i]) dem++;
 for(int i=1;i<n;i++)
 {
     ll x=a[1];
     for(int i=1;i<n;i++)
     {
         a[i]=a[i+1];
     }
     a[n]=x;
     for(int i=1;i<=n;i++)
     {
         if(a[i]==b[i])
            dem1++;
     }
   dem=max(dem,dem1);
   dem1=0;
 }
 cout<<dem;

}
