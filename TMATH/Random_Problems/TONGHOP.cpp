#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nmax 1000000
#define fi first
#define se second

pair<ll,ll> a[nmax];
pair<ll,ll> b[nmax];
pair<ll,ll> c[nmax];
ll m,n,P=0,q,g;
ll cmp(pair<ll,ll> x,pair<ll,ll> y)
{
    if(x.se!=y.se)
    return x.se<y.se;
    else if(x.se==y.se) return x.fi>y.fi;
}
int main()
{
 cin>>m>>n;
 for(int i=1;i<=n;i++)
 {
     cin>>a[i].fi>>a[i].se;
     c[i].fi=a[i].fi;
     c[i].se=i;
 }
 sort(a+1,a+n+1,cmp);
long long k=0;
 ll i=1;
  while(k<=m)
  {
    P+=a[i].se*a[i].fi;
    k+=a[i].fi;
    if(k>m)
    {
    q=k-m;
    a[i].fi-=q;

    b[i].fi=a[i].fi;
    b[i].se=i;
    P=P-q*a[i].se;
    }
    else
    {

    b[i].fi=a[i].fi;
    b[i].se=i;
    }
    i++;
    }
    cout<<P<<endl;
    for(int i=1;i<=n;i++)
    cout<<b[i].fi<<" "<<b[i].se<<endl;
    //sort(c+1,c+n+1);
//for(int i=1;i<=n;i++ )
 //cout<<c[i].se<<endl;


            }






