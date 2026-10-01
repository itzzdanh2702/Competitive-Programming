#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define nmax 400005
ll t;
bool nt[nmax+5];
vector<ll> a;
void sang()
{
memset(nt, true, sizeof nt);
  nt[0]=nt[1]=false;
 for(int i=2;i*i<=nmax;i++)
  if(nt[i])
      for(int t=i;t*i<=nmax;t++)
        nt[t*i]=false;
}
void mangnt()
{
    for(int i=2;i<=nmax;i++)
    {
        if(nt[i]==true) a.push_back(i);
    }
}
ll chat(ll x, ll d)
{
    ll l=1, r=a .size();
    ll ans=0;
    while(l<=r)
    {
        ll mid=(l+r)/2;
        if(a[mid]-x>=d)
        {
            ans=a[mid];
            r=mid-1;
        }
        else l=mid+1;
    }
    return ans;
}
int main()
{
    cin>>t;
     sang();
    mangnt();
    while(t--)
    {
        ll d;
        cin>>d;
        for(int i=0;i<a.size();i++)
        {
            if(a[i]-1>=d)
            {
                if(chat(a[i],d)!=0)
                {
                    cout<<a[i]*chat(a[i],d)<<endl;
                    break;
                }
            }
        }
    }


}
