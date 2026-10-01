#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, s, t;
ll x[5005], y[5005], r[5005], dp[5005];
bool visited[5005];

bool bfs(ll s)
{
    visited[s] = true;
    queue<ll> qu;
    qu.push(s);
    while (!qu.empty())
    {
        ll tmp = qu.front();
        qu.pop();
        for (auto x : ke[tmp])
        {
            if (!visited[x])
            {
                dp[x] = dp[tmp] + 1;
                qu.push(x);
                visited[x] = true;
            }
        }
    }
    if (dp[t] != 0)
        return true;
    return false;
}
int main()
{
    //freopen("CIRCLE.inp", "r", stdin);
    //freopen("CIRCLE.out", "w", stdout);
    cin >> n >> s >> t;
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i] >> r[i];
    }
    for (int i = 1; i <= n - 1; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            // R−r<OO′<R+r
            ll val = abs(x[j]-x[i]);
            if ((val >= abs (r[i] - r[j])) and (val <= r[i] + r[j]))
            {
                ke[i].push_back(j);
                ke[j].push_back(i);
            }
        }
    }
    memset(visited, false, sizeof(visited));
    memset(dp, 0, sizeof(dp));
    if (bfs(s))
        cout << dp[t]-1 ;
    else
        cout << "-1";
}
