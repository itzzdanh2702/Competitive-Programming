#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define nmax 1000000
ll a[nmax],n,b[nmax],t,u[nmax],k,dem=0,x,p,mi;
int BS(ll a[],ll x,ll l,ll r)
{
           ll p=1;
           while(l<=r){
           ll mid=(l+r)/2;
           if(a[mid]<=x)
           {
               p=mid;
               l=mid+1;

           }
            if(a[mid]>x) r=mid-1;
           }

           return p;

        }
        int main()
        {
            cin>>n;
           for(int i=1;i<=n;i++)
            cin>>a[i];
           sort(a+1,a+n+1);
           cin>>k;
           for(int i=1;i<=k;i++)
            cin>>b[i];
           for(int i=1;i<=k;i++)

           {
               ll t=BS(a,b[i],1,n);

              mi=min(abs(b[i]-a[t]),abs(b[i]-a[t+1]));
              cout<<mi<<endl;

           }




        }
