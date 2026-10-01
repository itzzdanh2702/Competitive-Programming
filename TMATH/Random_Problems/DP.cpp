#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define nmax 1000000
ll n,a[nmax],x,mi=1000000000,ma=-1000000000,pos,pos1=0,mi1=1000000000,mi2=1000000000;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n-1;i++)
            ma=max(ma,a[i]);

     for(int i=1;i<=n-1;i++)
        {
            if(a[i]==ma)
     {
         pos=i;
         break;
     }
        }
        if(pos==1)
        {
            for(int i=2;i<=n-1;i++)
    {
        mi=min(abs(a[i]-ma),mi);
    }
    for(int i=2;i<=n-1;i++)
    {
        if(abs(a[i]-ma)==mi)
            {
                x=a[i];
                pos1=i;
                break;
            }
    }
    for(int i=pos1+1;i<=n;i++)
        mi1=min(mi1,a[i]);
        }
        else
        {
         for(int i=1;i<=pos-1;i++)
    {
        mi=min(abs(a[i]-ma),mi);
    }
    for(int i=pos+1;i<=n-1;i++)
        mi2=min(mi2,abs(a[i]-ma));
    mi=min(mi,mi2);
   for(int i=pos+1;i<=n-1;i++)
   {
       if(abs(a[i]-ma)==mi)
       {
           pos1=i;

       }
   }
    pos1=max(pos,pos1);
    for(int i=pos1+1;i<=n;i++)
        mi1=min(mi1,a[i]);

        }
    cout<<ma<<" "<<x<<" "<<pos1;
}
