        #include<bits/stdc++.h>
        using namespace std;
        #define ll long long
        #define nmax 1000000
        ll a[nmax],n,b[nmax],t,u[nmax],x,k;
        int BS(ll a[],ll x,ll l,ll r)
        {
            ll mi=1e18;
            if(l>r) return 0;
            else
            {
                ll mid=(l+r)/2;
                if(a[mid]>=x)
                {
                mi=min(mi,a[mid]);
                BS(a,x,l,mid-1);
                }


                else BS(a,x,mid+1,r);

            }
               return mi;
        }
        int main()
        {
            cin>>n>>k;
            for(int i=1;i<=n;i++)
                {

                a[i]=i*i+1;
                }
            for(int i=1;i<=k;i++)
                {
                    cin>>x;
                    cout<<BS(a,x,1,n)<<endl;
                }



        }
