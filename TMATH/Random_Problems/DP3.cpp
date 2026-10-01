#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define nmax 1000000
ll n,a[nmax],l[nmax]={0},r[nmax]={0},t,sum,sum1 ;
int main()
{
    cin>>t;
    for(int i=1;i<=t;i++)
    {
    ll ma=-1000000;
    sum=0;sum1=0;
    l[nmax]={0};
    r[nmax]={0};
    cin>>n;
    for(int i=1;i<=n;i++)
    cin>>a[i];
    for(int i=1;i<=n;i++)
        {


            sum=sum+a[i-1];
            if(sum<0) sum=0;
            l[i]=max(l[i-1],sum);


        }


    for(int i=n;i>=1;i--)
    {
        sum1=sum1+a[i+1];
        if(sum1<0) sum1=0;
        r[i]=max(r[i+1],sum1);

    }

     for(int i=1;i<=n;i++)
        ma=max(ma,l[i-1]+r[i+1]);
     cout<<ma;
    }
}

