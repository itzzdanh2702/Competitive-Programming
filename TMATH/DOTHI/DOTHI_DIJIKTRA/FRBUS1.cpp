#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pil pair<ll, ll>
#define fi first
#define se second
#define tupi tuple<int, int, int>
#define inf 0x3f3f3f3f
const ll MAXN = 1e6 + 9;

int n, m, s, t;
int d[5][MAXN];
priority_queue<tupi, vector<tupi>, greater<tupi>> pq;
vector<pii> dinhke[MAXN];
void dijkstra(int ps)
{
    for (int i = 1; i <= n; i++)
    {
        dp[0][i] = dp[1]
    }
    d[0][ps] = 0;
    pq.push({0, 0, ps});
    while (pq.size())
    {
        int valu, choose, u;
        tie(valu, choose, u) = pq.top();
        pq.pop();
        if (d[choose][u] != valu)
            continue;
        for (auto x : dinhke[u])
        {
            int valv, v;
            tie(valv, v) = x;
            if (d[choose][v] > d[choose][u] + valv)
            {
                d[choose][v] = d[choose][u] + valv;
                pq.push({d[choose][v], choose, v});
            }
            if (choose == 0 && d[1][v] > d[0][u])
            {
                d[1][v] = d[0][u];
                pq.push({d[1][v], 1, v});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> s >> t;
    for (int i = 1; i <= m; i++)
    {
        int x, y, c;
        cin >> x >> y >> c;
        dinhke[x].push_back({c, y});
        dinhke[y].push_back({c, x});
    }
    dijkstra(s);
    if (d[1][t] > 1e9)
        cout << -1;
    else
        cout << d[1][t];
}
