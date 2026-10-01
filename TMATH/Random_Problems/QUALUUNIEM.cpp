#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define nmax 1000000
ll n,k,a[nmax],ans,ans1,S=0,temp[nmax];
int main()
{
  cin>>n>>k;
  for(int i=1;i<=n;i++)
  cin>>a[i];
  ll l=1,r=n;
  while(l<=r)
  {
    ll mid=(l+r)/2;
    for(int i=1;i<=mid;i++)
    {
       temp[i]=a[i]+mid*i;
    }
    sort(temp+1,temp+mid+1);
    for(int i=1;i<=mid;i++)
    {
      S+=a[i]+mid*i;
    }
    if(S<=k) 
    {
      ans=mid;
      ans1=S;
      l=mid+1;
    }
    else r=mid-1;
  }
  cout<<ans<<" "<<ans1;
}