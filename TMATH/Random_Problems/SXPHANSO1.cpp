#include<bits/stdc++.h>
using namespace std;
#define fl float
#define nmax 1000000
#define ii pair
#define fi first
#define se second

ii<fl,long long> q[nmax];
ii<fl,long long> h[nmax];
ii<long long,long long> k[nmax];
fl g, p[nmax],x,y,a[nmax],b[nmax];
long long A[nmax],B[nmax],m,n,dem=0,dem1=0,C;
long long cmp(ii<float,long long> x,ii<float,long long> y)
{

    return (x.fi<y.fi);

}
int main()
{
  cin>>m>>n>>C;
  for(int i=1;i<=m;i++)
        cin>>A[i];
  for(int j=1;j<=n;j++)
    cin>>B[j];
  for(int i=1;i<=m;i++)
  {
      for(int j=1;j<=n;j++)
      {
          dem++;
          x=A[i]/__gcd(A[i],B[j]);
          y=B[j]/__gcd(A[i],B[j]);
          p[dem]=float(x/y);
          q[dem].fi=p[dem];
          q[dem].se=x;
          h[dem].fi=p[dem];
          h[dem].se=y;

      }
  }
  sort(q+1,q+dem+1,cmp);
  sort(h+1,h+dem+1,cmp);
  for(int i=1;i<=dem;i++)
  {
     if((q[i].se!=q[i+1].se) or ((h[i].se!=h[i+1].se)))
     {
         dem1++;
         k[dem1].fi=q[i].se;
         k[dem1].se=h[i].se;

     }
     else if (q[i].se==q[i+1].se)
     {
         continue;
     }
  }

    cout<<k[C].fi<<" "<<k[C].se;
}
