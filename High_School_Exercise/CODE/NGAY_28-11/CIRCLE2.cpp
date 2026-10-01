#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, s, t;
ll x[1005], y[1005], r[1005], dp[1005];
bool visited[1005];
vector<ll> ke[1005];
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
    freopen("circle2.inp","r",stdin);
    freopen("circle2.out","w",stdout);
    cin >> n >> s >> t;
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i] >> y[i] >> r[i];
    }
    for (int i = 1; i <= n - 1; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            // R−r<OO′<R+r
            ll val = sqrt((x[j] - x[i]) * (x[j] - x[i]) + (y[j] - y[i]) * (y[j] - y[i]));
            if ((val >= abs(r[i] - r[j])) and (val <= r[i] + r[j]))
            {
                ke[i].push_back(j);     
                ke[j].push_back(i);
            }
        }
    }
    memset(visited, false, sizeof(visited));
    memset(dp, 0, sizeof(dp));
    if (bfs(s))
        cout << dp[t];
    else
        cout << "-1";
}