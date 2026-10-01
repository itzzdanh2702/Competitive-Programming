#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nmax 1000000
#define pii pair<ll, ll>
#define fi first
#define se second
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
struct tom
{
    ll w, u, v;
};
struct cmp
{
    bool operator()(tom a, tom b)
    {
        return a.w > b.w;
    }
};
ll a[1001][1001];
ll b[1001][1001];
ll d[1001][1001];
bool visited[1001][1001];
ll m, n;
ll x, y;
ll ans;
vector<tom> v[1001][1001];
void FAST()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
void prim()
{
    priority_queue<tom, vector<tom>, cmp> pq;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            d[i][j] = INF;
        }
    }
    d[1][1] = 0;
    pq.push({0, 1, 1});
    while (!pq.empty())
    {
        tom top = pq.top();
        pq.pop();
        if (visited[top.u][top.v])
            continue;
        visited[top.u][top.v] = true;
        ans += d[top.u][top.v];
        for (auto x : v[top.u][top.v])
        {
            if (d[x.u][x.v] > x.w)
            {
                d[x.u][x.v] = x.w;
                pq.push({d[x.u][x.v], x.u, x.v});
            }
        }
    }
}

int main()
{
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n - 1; j++)
        {
            cin >> x;
            v[i][j].push_back({x, i, j + 1});
            v[i][j + 1].push_back({x, i, j});
        }
    }
    for (int i = 1; i <= m - 1; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> y;
            v[i][j].push_back({y, i + 1, j});
            v[i + 1][j].push_back({y, i, j});
        }
    }
    prim();
    cout << ans;
}