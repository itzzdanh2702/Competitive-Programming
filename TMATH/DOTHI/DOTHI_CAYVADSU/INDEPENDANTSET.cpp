#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
#define ll long long
#define MAXN 1000005
#define oo 1000000000

ll n;
ll dp[MAXN][1];

bool visited[MAXN];

vector<ll> vec[MAXN];

void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

void cal(ll u)
{
    dp[u][1] = dp[u][0] = 1;
    visited[u] = true;
    for(auto x: vec[u])
    {
        if(!visited[x])
        {
            cal(x);
            dp[u][0] = dp[x][1] * dp[u][0];
            dp[u][1] = dp[u][1] *(dp[x][0]+dp[x][1]);
        }
    }
}
int main()
{
    FAST();
    cin >> n;
    for (int i = 1; i <= n - 1; ++i)
    {
        ll u, v;
        cin >> u >> v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    cal(1);
    cout<<dp[1][1]+dp[1][0];
}
