#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define nmax 1000000
#define fi first
#define se second
ll a[nmax],n,dem=0,k,S[nmax],x,c[nmax],p,q,h,g[nmax ];
pair<ll,ll> b[nmax];

int BS(ll a[],ll l,ll r,ll x)
{
    if(l>r) return 0;
    else
    {
        ll mid=(l+r)/2;
        if(a[mid]==x)
            return a[mid];
        else if(a[mid]>x)
            BS(a,l,mid-1,x);
        else BS(a,mid+1,r,x);
    }
}
int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            c[a[i]]=i;
        }
        sort(a+1,a+n+1);
    for(int i=1;i<=n-1;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            dem++;
            S[dem]=a[i]+a[j];
            b[dem].fi=a[i];
            b[dem].se=a[j];
        }
    }
    for(int i=1;i<=dem;i++)
    {
        x=k-S[i];
        if(BS( a,1,n, x)!=0)
        {
            p=b[i].fi;
            q=b[i].se;
            h=BS( a,1,n, x);
            break;
        }
    }

       g[1]=c[p];
       g[2]=c[q];
       g[3]=c[h];
       sort(g+1,g+3+1);
       ll dem3=0;
       for(int i=1;i<=3;i++)
       {
           if(g[i]!=0)
        {
            cout<<g[i]<<" ";
            dem3++;
       }
       }
      if(dem3==0) cout<<"-1";


}

