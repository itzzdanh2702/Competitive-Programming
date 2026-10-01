        #include<bits/stdc++.h>
        using namespace std;
        #define ll long long
        #define nmax 1000000
        #define fi first
        #define se second
        #define ii pair
        ll n,f[nmax],k[nmax],dem=1,dem1=0,a,b,P=1,Q=1;
        //pair<ll,ll> a[nmax];
        //pair<ll,ll> p[nmax];
        ll cmp(ii<ll,ll> x,ii<ll,ll> y)
        {
            if (x.fi!=y.fi)
            return (x.fi>y.fi);
            else return (x.se<y.se);
        }
        int main()
        {
          while(cin>>a>>b)
          {
              P*=a/__gcd(a,b);
              Q*=b/__gcd(a,b);
          }
          cout<<P/(__gcd(P,Q))<<" "<<Q/__gcd(P,Q);
        }
