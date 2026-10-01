#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nmax 1000000
#define pii pair<ll, ll>
#define fi first
#define se second
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
ll a[nmax];
ll d[nmax];
bool visited[nmax];
ll m, n, s, t;
ll q;
ll ans;
ll kq = -INF;
vector<pii> vec[nmax], ans1;

void FAST()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void dijiktra(int u)
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    for (int i = 1; i <= n; i++)
        d[i] = INF;
    pq.push({0, u});
    d[u] = 0;
    while (!pq.empty())
    {
        pii top = pq.top();
        pq.pop();
        ll valu = top.fi;
        ll u = top.se;
        if (top.fi != d[u])
            continue;
        for (auto x : vec[u])
        {
            ll v = x.fi;
            ll valv = x.se;
            if (d[v] > d[u] + valv)
            {
                d[v] = d[u] + valv;
                pq.push({d[v], v});
            }
        }
    }
}
int main()
{
    FAST();
    cin >> n >> m;
    while(m--)
    {
        ll u,v,w;
        cin>>u>>v>>w;
        vec[u].push_back({v,w});
        vec[v].push_back({u,w});
    }
    ll mi = INF;
    for(int i=1;i<=n;i++)
    {
        ll ma = -INF;
        dijiktra(i);
        for(int j=1;j<=n;j++)
        {
            if(i!=j)
            ma = max(d[j],ma);
        }
        mi = min(mi,ma);
    }
    cout<<mi;

}