#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nmax 1000000
#define pii pair<ll, ll>
#define fi first
#define se second
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
ll a[nmax];
ll d[nmax];
ll S = 0;
bool visited[nmax];
bool inside[nmax];
ll m, n;
ll ans;
vector<pii> dinhke[nmax];
priority_queue<pii, vector<pii>, greater<pii>> pq;
void FAST()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int main()
{
    FAST();
    cin >> n;
    /*/
    for (int i = 1; i <= n; i++)
        d[i] = INF;
    while (m--)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        dinhke[u].push_back({v, w});
        dinhke[v].push_back({u, w});
        S += w;
    }
    d[1] = 0;
    pq.push({d[1], 1});
    while (!pq.empty())
    {
        pii node = pq.top();
        pq.pop();
        ll u = node.second;
        if (inside[u] == 1)
            continue;
        inside[u] = 1;
        ans = max(ans,d[u]);
        for (auto x : dinhke[u])
        {
            int v = x.fi;
            int w = x.se;
            if (w < d[v])
            {
                d[v] = w;
                pq.push({d[v], v});
            }
        }
    }
    cout << ans;
    /*/
    ll ma = -INF;
    ll mi = INF;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        ma = max(ma,a[i]);
        mi = min(mi,a[i]);
    }
    cout<<ma - mi;

}