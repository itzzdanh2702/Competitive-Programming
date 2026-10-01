#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define nmax 1000000
ll a[nmax],n,b[nmax],t,u[nmax],k,dem=0,x,p,S=0,ma=-1e9,h;
ll BS(ll a[],ll l,ll r,ll x)
{
    if(l>r) return 0;
    else
    {
      ll mid=(l+r)/2;

      if(a[mid]>x)
      {
        S+=a[mid]-x;
         BS(a,mid+1,r,x);
        BS(a,l,mid-1,x);
      }
      else if(a[mid]<=x)
      {

       BS(a,mid+1,r,x);
      }
    }
    return S;
}
int main()
{

  cin>>n>>h;
  for(int i=1;i<=n;i++)
  {
      cin>>a[i];
      ma=max(a[i],a[i-1]);

  }
  sort(a+1,a+n+1);
  for(int i=h;i<=ma;i++)
  {

   dem++;
   b[dem]=BS( a,1,n,i);
   if(b[dem]<h)
   {
       cout<<i-1;
       break;
   }

  S=0;
  }

}
