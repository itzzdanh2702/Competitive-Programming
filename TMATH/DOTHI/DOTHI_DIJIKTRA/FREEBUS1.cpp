#include <bits/stdc++.h>
using namespace std;
#define ll long long
const long long MOD = 1000000007;
#define MAXN 1000005
#define pii pair<ll, ll>
#define fi first
#define se second
#define tupi tuple<ll,ll,ll>
const ll INF = 1e18;
ll dp[MAXN][5];
vector<pii> dinhke[MAXN];
void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll n, m, s, t;
void dijikstra(ll s)
{
    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = dp[i][1] = INF;
    }
    priority_queue<tupi,vector<tupi>,greater<tupi>> pq;
    dp[s][0] = 0;
    pq.push({0, s, 0});
    while (!pq.empty())
    {
        ll valu,u,choose;
        tie(valu,u,choose) = pq.top();
        pq.pop();
        if (dp[u][choose] != valu) continue;
        for (auto x : dinhke[u])
        {
            ll v,valv;
            tie(v,valv) = x;
            if (dp[v][choose] > dp[u][choose] + valv)
            {
                dp[v][choose] = dp[u][choose] + valv;
                pq.push({dp[v][choose],v,choose});
            }
            if(choose==0)
            {
                if(dp[v][1]>dp[u][0])
                {
                    dp[v][1] = dp[u][0];
                    pq.push({dp[v][1],v,1});
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
        ll u, v, w;
        cin >> u >> v >> w;
        dinhke[u].push_back({v, w});
        dinhke[v].push_back({u, w});
    }
    dijikstra(s);
    if(dp[t][1]==INF) cout<<"-1";
    else 
    cout<<dp[t][1];
}