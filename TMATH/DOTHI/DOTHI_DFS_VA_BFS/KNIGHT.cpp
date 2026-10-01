#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nmax 1000000
#define pii pair<ll, ll>
#define fi first
#define se second
ll dp[26][26];
ll n;
bool visited[26][26];
bool bfs(ll i, ll j, ll a, ll b)
{
    memset(dp, 0, sizeof(dp));
    memset(visited,false,sizeof(visited));
    queue<pii> qu;
    visited[i][j]=true;
    qu.push({i, j});
    ll dx[] = {a, a, -a, -a, b, b, -b, -b};
    ll dy[] = {b, -b, b, -b, a, -a, a, -a};
    while (!qu.empty())
    {
        for (int p = 0; p <= 7; p++)
        {
            pii top = qu.front();
            qu.pop();
            ll i1 = top.fi + dx[p];
            ll j1 = top.se + dy[p];
            if ((!visited[i1][j1]) and (i1 <= n) and (j1 <= n) and (i1 >= 1) and (j1 >= 1))
            {
                dp[i1][j1] = dp[top.fi][top.se] + 1;
                visited[i1][j1] = true;
                qu.push({i1, j1});
                if((i1==n) and (j1==n)) return true;

            }
        }
    }

    return false;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n - 1; i++)
    {
        for (int j = 1; j <= n - 1; j++)
        {
            if (bfs(1, 1, i, j))
            {
                cout << dp[n][n] << ' ';
            }
            else
                cout << "-1";
        }
        cout << endl;
    }
}

