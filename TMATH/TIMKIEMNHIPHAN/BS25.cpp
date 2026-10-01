#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define nmax 1000005
ll a,b,k,f[nmax],ans,mi;
bool nt[nmax];
void sang()
{

    nt[0]=nt[1]=false;
    for(int i=2;i<=nmax;i++) nt[i]=true;
    for(int i=2;i*i<=nmax;i++)
    {
        if(nt[i])
        {
            for(int j=i*i;j<=nmax;j+=i)
            {
                nt[j]=false;
            }
        }
    }
}
bool check(ll mid)
{
    for(int i=a;i<=b-k+1;i++)
        {
            if( f[i+mid-1]-f[i-1]<k)
                return false;       
        }
    return true;
}
int main()
{
    sang();
    cin>>a>>b>>k;
    for(int i=1;i<=nmax;i++)
    {
        if(nt[i])
        {
            f[i]=f[i-1]+1;
        }
        else f[i]=f[i-1];
    }
    ll l=1,r=b-a+1;
    while(l<=r)
    {
        ll mid=(l+r)/2;
        if(check(mid))
        {
            ans=mid;
            //mi=min(ans,mi);
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }
    cout<<ans;



}
//8 7
//7 7 
