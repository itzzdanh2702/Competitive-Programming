#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define nmax 1000000
#define fi first 
#define se second 
#define pii pair<ll,ll>
#define li pair<pii,ll>
ll mark[nmax];
li dinhke[nmax];
ll n,m;
ll q;
ll kq = 1;
ll s1[nmax];
ll parent[nmax];
int scs(ll n)
{
    ll dem1=0;
    while(n/2!=0)
    {
        dem1+=1;
        n/=2;
    }
    return dem1;
}
bool cmp(li x,li y)
{
    
    return x.se<y.se;
}
int find(int n)
{
    while(parent[n]!=-1)
    {
        n=parent[n];
    }
    return n;
}
void join(int x,int y)
{
    if(s1[x]>s1[y])
    {
        s1[x]+=s1[y];
        parent[y]=x;
    }
    else 
    {
        s1[y]+=s1[x];
        parent[x]=y;
    }
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>dinhke[i].fi.fi>>dinhke[i].fi.se>>q;
        dinhke[i].se = scs(q);
    }
    sort(dinhke+1,dinhke+m+1,cmp);
    for(int i=1;i<=n;i++) 
    {
        parent[i]=-1;
        s1[i]=1;
    }
    ll kq=0;
    for(int i=1;i<=m;i++)
    {
        int u=dinhke[i].fi.fi;
        int v=dinhke[i].fi.se;
        int uu=find(u);
        int vv=find(v);
        if(uu!=vv)
        {
            mark[i]=1;
            kq+=dinhke[i].se;
            join(uu,vv);
        }
    }
    cout<<kq;
}