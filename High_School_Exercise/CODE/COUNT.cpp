#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define nmax 1000005
ll n,dem=0;
bool nt[nmax];
void sang()
{
    nt[0]=nt[1]=false;
    for(int i=2;i<=nmax;i++)
        nt[i]=true;
    for(int i=2;i*i<=nmax;i++)
    {
        if(nt[i])
        {
            for(int j=i*i;j<=nmax;j+=i)
                nt[j]=false;
        }
    }
}
int main()
{
    freopen("COUNT.INP","r",stdin);
    freopen("COUNT.OUT","w",stdout);
    sang();
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        if(nt[i])
            dem++;
    }
    cout<<n-dem-1;
}
