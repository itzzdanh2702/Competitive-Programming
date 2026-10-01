#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n, m, a[1000006];
ll check(ll x)
{
    ll e=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]>x) e+=a[i]/x;
    }
    return e;
}
ll solve(ll left, ll right){
    ll ans=0;
    while(left<=right)
   {
       ll mid=(left+right)/2;
       ll res=check(mid);
       if(res==m) return mid;
       if(res>m)  {left=mid+1; ans=mid;}
       else right=mid-1;
   }
   return ans;
}
int main()
{
   cin>>n>>m;
   for(int i=1;i<=n;i++) cin>>a[i];
   sort(a+1,a+1+n);
   ll left=1,right=a[n];
   cout<<solve(left,right);

}
