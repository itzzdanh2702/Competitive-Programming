#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nmax 100005
ll m, n, s, t;
ll dp[nmax];
bool visited[nmax];
vector<ll> dinhke[nmax], dinhke1[nmax], ans;
void bfs(int k)
{
    queue<ll> qu;
    qu.push(k);
    visited[k] = true;
    while (!qu.empty())
    {
        ll tmp = qu.front();
        qu.pop();
        for (auto x : dinhke[tmp])
        {
            if (!visited[x])
            {
                qu.push(x);
                visited[x] = true;
                dp[x] = dp[tmp] + 1;
            }
            if (dp[x] == dp[tmp] + 1)
            {
                dinhke1[x].push_back(tmp);
            }
        }
    }
    qu.push(t);
    ans.push_back(t);
    if (!dinhke[t].empty())
    {
        while (!qu.empty())
        {
            ll tmp1 = qu.front();
            qu.pop();
            for (auto it : dinhke1[tmp1])
            {
                if (visited[it])
                {
                    ans.push_back(it);
                    visited[it] = false;
                    qu.push(it);
                }
            }
        }
    }
    sort(ans.begin(), ans.end());
    for (auto x : ans)
        cout << x << ' ';
}
int main()
{
    cin >> m >> n >> s >> t;
    while (n--)
    {
        ll u, v;
        cin >> u >> v;
        dinhke[u].push_back(v);
        dinhke[v].push_back(u);
    }
    bfs(s);
}