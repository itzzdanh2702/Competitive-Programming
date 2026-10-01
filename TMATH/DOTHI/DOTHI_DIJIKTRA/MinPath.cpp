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
vector<pii> vec[nmax];

void FAST()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void dijiktra(int u)
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    fill(d, d + nmax, INF);
    pq.push({1, u});
    d[u] = 1;
    visited[u] = true;
    while (!pq.empty())
    {
        pii top = pq.top();
        pq.pop();
        if (top.fi > d[top.se])
            continue;

        for (auto x : vec[top.se])
        {
            if (d[x.fi] > (d[top.se] | x.se))
            {
                d[x.fi] = (d[top.se] | x.se);
                pq.push({d[x.fi], x.fi});
            }
        }
    }
}
int main()
{
    FAST();
    cin >> n >> m;
    while (m--)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        vec[u].push_back({v, w});
        vec[v].push_back({u, w});
    }
    cin >> s >> t;
    dijiktra(s);
    if (d[t] == INF)
        cout << "-1";
    else
        cout << d[t];
}