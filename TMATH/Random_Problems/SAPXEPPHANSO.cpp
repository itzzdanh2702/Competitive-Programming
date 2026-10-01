#include<bits/stdc++.h>
using namespace std;
#define fl float
#define nmax 1000000
#define ii pair
#define fi first
#define se second
//ii<long long ,long long> k[nmax];
ii<fl,long long> q[nmax];
ii<fl,long long> h[nmax];
fl g, p[nmax],x,y;
long long A[nmax],B[nmax],m,n,dem=0;
long long cmp(ii<float,long long> g,ii<float,long long> k)
{
	if (g.fi!=k.fi)
    return (g.fi>k.fi);
    else return (g.se>k.se);
}
int main()
{
  cin>>m>>n;
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
  sort(p+1,p+dem+1,cmp);
  for(int i=1;i<=dem;i++)
  {
     cout<<q[i].se<<" "<<h[i].se<<endl;
  }
}
