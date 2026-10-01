#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define nmax 1000000
ll n,a[nmax],dem=0,t,x;
bool BS(ll a[],ll l,ll r,ll x)
{
    if(l>r) return false;
    else
    {
        while(l<=r)
        {
            ll mid=(l+r)/2;
            if(a[mid]==x)
                return true;
            else if(a[mid]>x)
                r=mid-1;
            else l=mid+1;
        }

    }
    return false;
}
int main()
{
  cin>>n;
  for(int i=1;i<=n;i++)
   cin>>a[i];
   sort(a+1,a+n+1);
  cin>>t;
  for(int i=1;i<=t;i++)
  {
      cin>>x;
       if(BS(a,1,n,x))
       {

       auto it1=lower_bound(a+1,a+n+1,x);
       auto it2=upper_bound(a+1,a+n+1,x);
       if(*it1==*it2) cout<<"1"<<endl;
       else cout<< (it2-a)-(it1-a)<<endl;
       }
       else cout<<"0"<<endl;
  }
}

