#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define nmax 10000005
bool isprime[nmax];
ll n,MOD=1000000007,S=1;
void sang()
{
    for(int i=1;i<=nmax;i++)
        isprime[i]=true;
    isprime[0]=isprime[1]=false;

    for(int i=2;i*i<=nmax;i++ )
    {
        if(isprime[i])
        {
            for(int j=i*i;j<=nmax;j+=i)
                isprime[j]=false;
        }
    }
}
ll mu1(ll a,ll n)
{
    if(n==0) return 1;
    ll tam=mu1(a,n/2);
    tam=(tam*tam)%MOD;
    if(n%2!=0) tam=(tam*a)%MOD;
    return tam%MOD;
}
ll mu(ll n,ll k)
{
    ll dem=0;
    while(n>0)
    {
        dem+=n/k;
        n/=k;
    }
       return dem;
}
int main()
{
    sang();
    cin>>n;
    for(int i=2;i<=n;i++)
    {
        if(isprime[i])
        {
            if(mu(n,i)%2==0)
            {
              S=(S*mu1(i,mu(n,i)))%MOD;
            }
            else S=(S*mu1(i,mu(n,i)-1)))%MOD;

        }
    }
    cout<<S;
}
