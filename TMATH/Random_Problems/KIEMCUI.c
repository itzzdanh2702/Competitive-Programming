#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define nmax 1000000
ll a[nmax],n,b[nmax],t,u[nmax],k,dem=0,x,p,S=0,ma=-1e9,p;

int main()
{
  cin>>n>>h;
  for(int i=1;i<=n;i++)
  {
      cin>>a[i];
      ma=max(a[i],a[i-1]);

  }
  for(int i=1;i<=ma;i++)
  {
   ll S=0,dem=0,l=1,r=n;
   while(l<=r)
   {
      ll mid=(l+r)/2;
      if(a[mid]>i)
      {
        S+=a[mid];
        dem++;
        r=mid-1;

      }
      else if(a[mid]<i)
      {

       l=mid+1;
      }
   }

   if(S-dem*i==h) p=i,break;

  }
  cout<<p;
}





}
