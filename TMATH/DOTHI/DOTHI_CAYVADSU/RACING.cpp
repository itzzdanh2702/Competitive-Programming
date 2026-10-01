#include<bits/stdc++.h>
#define ll long long

ll const nmax = 1e5 + 5;

using namespace std;

ll n,m,parent[nmax],kq,S,ans,s[nmax];
struct vi
{
    ll u,v,c;
};
vi a[nmax];
bool cmp(vi a, vi b)
{
    return a.c > b.c;
}

void make_set()
{
    for(int i = 1 ; i <= n ; i++)
    {
        parent[i] = i;
        s[i]++;
    }
}

int findroot(int u)
{
    if (parent[u] == u) return u;
    return findroot(parent[u]);
}

void mergeroot(int x,int y)
{
    int u = findroot(x) , v = findroot(y);
    if (u != v)
    {
        if (s[u] >= s[v])
        {
            s[u] += s[v];
            parent[v] = u;
        }
        else
        {
            s[v] += s[u];
            parent[u] = v;
        }
    }
}

bool check(int u, int v)
{
    if (findroot(u) == findroot(v))
        return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    make_set();
    for (int i = 1 ; i <= m ; i++)
    {
        cin >> a[i].u >> a[i].v >> a[i].c;
        S += a[i].c;
    }
    sort(a + 1 , a + m + 1 , cmp);
    for (int i = 1 ; i <= m ; i++)
    {
        if (check(a[i].u , a[i].v))
        {
            ans++;
            kq += a[i].c;
            mergeroot(a[i].u , a[i].v);
            if (ans == n - 1)
            {
                cout << S - kq;
                return 0;
            }
        }
    }
    return 0;
}