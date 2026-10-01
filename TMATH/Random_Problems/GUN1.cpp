#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define nmax 1000000
ll n,t,a,b,dem=0,doi1=0,doi2=0;
struct tom
{
    ll time,ban,biban;
} q[nmax];
bool cmp(tom cr, tom pr)
{
	return cr.ban<pr.ban;
}
int main()
{
    freopen("GUN.INP","r",stdin);
    freopen("GUN.OUT","w",stdout);
    while(cin>>t>>a>>b)
    {
        dem++;
        q[dem].ban=a;
        q[dem].biban=b;
        q[dem].time=t;
    }
    sort(q+1,q+dem+1,cmp);
    for(int i=1;i<=dem;i++)
    {
        if(q[i].ban>q[i].biban)
        {
            doi2+=100;
            if((q[i].ban==q[i-1].ban) and (q[i].time-q[i-1].time<=10))
                doi2+=50;
        }
        else
        {
            doi1+=100;
            if((q[i].ban==q[i-1].ban) and (q[i].time-q[i-1].time<=10))
                doi1+=50;
        }

    }
    cout<<doi1<<" "<<doi2;
}
