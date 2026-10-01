#include<bits/stdc++.h>
        using namespace std;
        #define ll long long
        #define nmax 1000000
        ll a[nmax],n,b[nmax],t,u[nmax],k,dem=0,x,p;
        ll BS(ll a[],ll x,ll l,ll r)
        {
           ll p=0   ;
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

           {
              cin>>b[i];
              x=b[i];

              if (BS( a, x, 1,n)==0)
               cout<<"0"<<endl;
              else
                cout<<BS( a, x, 1,n)<<endl;

           }




        }
