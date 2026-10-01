#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nmax 1000000
ll root[nmax];
ll n, m;
ll dem;
vector<ll> v;
int findroot(int u)
{
    if (root[u] == u)
        return u;
    return root[u] = findroot(root[u]);
}
void mergeroot(ll u, ll v)
{
    ll x = findroot(u);
    ll y = findroot(v);
    if (x != y)
        root[x] = y;
}
int main()
{
    cin >> n >> m;
    ll edge = m;
    for(int i=1;i<=n;i++)
    root[i]=i;
    while (m--)
    {
        ll u, v;
        cin >> u >> v;
        mergeroot(u, v);
    }
    for(int i=1;i<=n;i++)
    v.push_back(findroot(i));
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++)
    if(v[i]!=v[i+1])
    {
        dem++;
    }
    if(n==edge+1)
    {
     if (dem==1)  cout<<"YES";
    else  cout<<"NO";
    }
    else cout<<"NO";
}