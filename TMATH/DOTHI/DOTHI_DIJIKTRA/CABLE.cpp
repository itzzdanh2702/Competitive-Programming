#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
#define MAXN 1000005
#define oo 1000000000000000000
#define PLL pair<long long, long long>

void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int n, nx, ny;
int s, t;
long long U[MAXN];
long long V[MAXN];
long long W[MAXN];
long long X[MAXN];
long long Y[MAXN];
vector<pair<long long, long long>> adj[MAXN];
priority_queue<PLL, vector<PLL>, greater<PLL>> Q;
long long ans = oo;

void dijikstra()
{
    for (int i = 1; i <= nx; i++)
        adj[U[i]].push_back({V[i], W[i]});
    X[s] = 0;
    Q.push({0, s});
    while (!Q.empty())
    {
        PLL top = Q.top();
        Q.pop();
        long long u = top.second;
        long long kc = top.first;
        if (kc > X[u])
            continue;
        for (PLL x : adj[u])
        {
            long long v = x.first;
            long long w = x.second;
            if (X[v] > X[u] + w)
            {
                X[v] = X[u] + w;
                Q.push({X[v], v});
            }
        }
    }
    Y[t] = 0;
    for (int i = 1; i <= n; i++)
        adj[i].clear();
    for (int i = 1; i <= nx; i++)
        adj[V[i]].push_back({U[i], W[i]});
    Q.push({0, t});
    while (!Q.empty())
    {
        PLL top = Q.top();
        Q.pop();
        long long u = top.second;
        long long kc = top.first;
        if (kc > Y[u])
            continue;
        for (PLL x : adj[u])
        {
            long long v = x.first;
            long long w = x.second;
            if (Y[v] > Y[u] + w)
            {
                Y[v] = Y[u] + w;
                Q.push({Y[v], v});
            }
        }
    }
}


int main()
{
    FAST();

    cin >> n >> nx >> ny >> s >> t;

    for (int i = 1; i <= n; i++)
        X[i] = Y[i] = oo;

    for (int i = 1; i <= nx; i++)
        cin >> U[i] >> V[i] >> W[i];

    dijikstra();
    for (int i = 1; i <= ny; i++)
    {
        long long u, v, w;
        cin >> u >> v >> w;
        ans = min({ans, X[u] + w + Y[v], X[v] + Y[u] + w});
    }
    if(ans == oo) cout<<"-1";
    else cout<<ans;
}