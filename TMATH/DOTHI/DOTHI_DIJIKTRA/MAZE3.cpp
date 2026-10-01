#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nmax 1000000
#define pii pair<ll, ll>
#define fi first
#define se second
#define li pair<ll, pii>
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
ll dp[1001][1001];
ll a[1001][1001];
ll b[1001][1001];
ll dx[] = {0, 1, 0, -1};
ll dy[] = {1, 0, -1, 0};
ll ans;
ll mi = INF;
ll m, n, sx, sy;
void FAST()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
struct tom
{
    ll u, v, w;
};
vector<tom> adj[1001][1001];
struct cmp
{
    bool operator()(tom a, tom b)
    {
        return a.w > b.w;
    }
};
void dijikstra(ll su, ll sv)
{
    priority_queue<tom, vector<tom>, cmp> pq;
    for (int i = 0; i <= m + 1; i++)
    {
        for (int j = 0; j <= n + 1; j++)
        {
            dp[i][j] = INF;
        }
    }
    dp[su][sv] = 0;
    pq.push({su, sv, dp[su][sv]});
    while (!pq.empty())
    {
        tom top = pq.top();
        pq.pop();
        for (auto x : adj[top.u][top.v])
        {
            if ((x.u > 0) and (x.u < m + 1) and (x.v > 0) and (x.v < n + 1))
            {
                if (dp[x.u][x.v] > dp[top.u][top.v] + x.w)
                {
                    dp[x.u][x.v] = dp[top.u][top.v] + x.w;
                    pq.push({x.u, x.v, dp[x.u][x.v]});
                }
            }
            else if ((x.u == 0) or (x.u == m + 1) or (x.v == 0) or (x.v == n + 1))
            {
                if (dp[x.u][x.v] > dp[top.u][top.v] + x.w)
                {

                    dp[x.u][x.v] = dp[top.u][top.v] + x.w;
                    pq.push({x.u, x.v, dp[x.u][x.v]});
                }
            }
        }
    }
}

int main()
{
    cin >> m >> n >> sx >> sy;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n + 1; j++)
        {
            cin >> a[i][j];
            adj[i][j - 1].push_back({i, j, a[i][j]});
            adj[i][j].push_back({i, j - 1, a[i][j]});
        }
    }
    for (int i = 1; i <= m + 1; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> b[i][j];
            adj[i - 1][j].push_back({i, j, b[i][j]});
            adj[i][j].push_back({i - 1, j, b[i][j]});
        }
    }

    dijikstra(sx, sy);
    for (int i = 0; i <= m + 1; i++)
    {
        for (int j = 0; j <= n + 1; j++)
        {
            if ((i == 0) or (i == m + 1) or (j == 0) or (j == n + 1))
            {
                mi = min(dp[i][j], mi);
            }
        }
    }
    cout << mi;
}