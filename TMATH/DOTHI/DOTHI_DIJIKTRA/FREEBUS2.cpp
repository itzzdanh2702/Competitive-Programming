#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
#define MAXN 100005
#define ll long long
const ll oo = 1e18;
#define pii pair<int, int>
#define li pair<int, pii>
#define fi first
#define se second

void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

struct tom
{
    int nodeU, layerU;
    ll valU;
    bool operator<(const tom &o) const
    {
        return valU > o.valU;
    }
};

int n, m, k, s, t;
ll dp[MAXN][10];
vector<pii> vec[MAXN];

void dijisktra(int s)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            dp[i][j] = oo;
        }
    }
    priority_queue<tom> pq;
    pq.push({s, 0, 0});
    dp[s][0] = 0;
    while (!pq.empty())
    {
        tom top = pq.top();
        pq.pop();
        if (top.valU > dp[top.nodeU][top.layerU])
            continue;
        for (auto x : vec[top.nodeU])
        {
            int nodeV = x.fi;
            int valV = x.se;
            if (dp[nodeV][top.layerU] > dp[top.nodeU][top.layerU] + valV)
            {
                dp[nodeV][top.layerU] = dp[top.nodeU][top.layerU] + valV;
                pq.push({nodeV, top.layerU, dp[nodeV][top.layerU]});
            }
            if ((top.layerU < k) and (dp[nodeV][top.layerU + 1] > dp[top.nodeU][top.layerU]))
            {
                dp[nodeV][top.layerU + 1] = dp[top.nodeU][top.layerU];
                pq.push({nodeV, top.layerU + 1, dp[nodeV][top.layerU + 1]});
            }
        }
    }
}
int main()
{
    FAST();
    cin >> n >> m >> k >> s >> t;
    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        vec[u].push_back({v, w});
        vec[v].push_back({u, w});
    }
    dijisktra(s);
    ll ans = oo;
    for (int i = 0; i <= k; i++)
    {
        ans = min(ans, dp[t][i]);
    }
    cout << ans;
}
