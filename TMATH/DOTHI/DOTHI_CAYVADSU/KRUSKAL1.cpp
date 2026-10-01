#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define nmax 1000000
#define pii pair<ll,ll>
#define lpii pair<pii,ll>
#define fi first
#define se second
const ll MOD = 1e9 + 7;
ll a[nmax];
ll m,n;
ll parent[nmax];
ll sl[nmax];
ll kq;
bool visited[nmax];
lpii v[nmax];
bool cmp(lpii x,lpii y)
{
    return x.se<y.se;
}
int find(int n)
{
    while (parent[n] != -1)
    {
        n = parent[n];
    }
    return n;
}
void join(int u,int v)
{
    if(sl[u]>sl[v])
    {
        sl[u]+=sl[v];
        parent[v] = u;
    }
    else 
    {
        sl[v]+=sl[u];
        parent[u] = v;
    }
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>v[i].fi.fi>>v[i].fi.se>>v[i].se;
    }
    sort(v+1,v+m+1,cmp);
    for(int i=1;i<=n;i++)
    {
        parent[i] = -1;
        sl[i] = 1;
    }
    for(int i=1;i<=m;i++)
    {
        ll uu = find(v[i].fi.fi);
        ll vv = find(v[i].fi.se);
        if(uu!=vv)
        {
            kq+=v[i].se;
            join(uu,vv);
        }
    }
    cout<<kq;
}