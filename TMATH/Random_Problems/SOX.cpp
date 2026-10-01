#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define nmax 1000000
#define fi first
#define se second
string S;
pair<ll,ll> b[nmax];
ll x,dem1=0,a[nmax],dem,k[nmax],p[nmax],dem2=0;
int main()
{
    cin>>S>>x;
    S[S.size()]='-1';
    for(int i=0;i<=S.size();i++)
    {
        if(int(S[i]-48)==x)
           {
               dem++;
               dem2++;
           }

        else
            {
               dem1++;
               a[dem1]=dem;
               dem=0;

            }
           }
    if(dem2!=0)
    {
    sort(a+1,a+dem1+1);



    p[dem1]=1;
    for(int i=dem1-1;i>=1;i--)
    {

        k[i]=k[i+1]+a[i+1];
        p[i]=dem1-i+1+k[i]-(dem1-i)*a[i];


    }

    for(int i=1;i<=dem1;i++)
   {
       if(a[i]==a[i-1])
       {
           p[i]=p[i-1];
       b[i].fi=a[i];
       b[i].se=p[i];
       cout<<b[i].fi<<" "<<b[i].se<<endl;
       }
       else
       {
           b[i].fi=a[i];
       b[i].se=p[i];
       cout<<b[i].fi<<" "<<b[i].se<<endl;
       }
   }
    }

}
