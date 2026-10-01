#include <bits/stdc++.h>
using namespace std;
#define ll long long
const long long MOD = 1000000007;
#define MAXN 100000
#define oo 1000000000
#define pii pair<int, int>
#define fi first
#define se second

void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int n, m, s, t;
int dp[MAXN];
ll dist[MAXN];
bool visited[MAXN][1];
vector<pii> vec[MAXN];

void bfs(int u)
{
    for (int i = 1; i <= n; i++)
        dp[i] = oo;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dp[u] = 0;
    visited[u][0] = true;
    pq.push({0, u});
    while (!pq.empty())
    {
        pii top = pq.top();
        pq.pop();
        if ((top.se == t) and (dist[top.se] % 2 == 1))
        {
            cout << top.fi;
            exit(0);
        }
        for (auto x : vec[top.se])
        {
            dist[x.fi] = dist[top.se] + 1;
            if (!visited[x.fi][dist[x.fi] % 2])
            {
                if (dp[x.fi] > dp[top.se] + x.se)
                {
                    dp[x.fi] = dp[top.se] + x.se;
                    visited[x.fi][dist[x.fi] % 2] = true;
                    pq.push({dp[x.fi], x.fi});
                }
            }
        }
    }
}
int main()
{
    FAST();
    cin >> n >> m >> s >> t;
    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        vec[u].push_back({v, w});
        vec[v].push_back({u, w});
    }
    bfs(s);
}