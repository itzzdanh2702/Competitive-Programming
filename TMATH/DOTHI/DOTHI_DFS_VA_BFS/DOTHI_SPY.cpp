#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nmax 1000000
#define pii pair<ll, ll>
#define fi first
#define se second

ll dx[] = {-1, 0, 1, 0};
ll dy[] = {0, -1, 0, 1};
ll m, n, x, y, s, t, p, q;
ll trace1[1001][1001], trace2[1001][1001];
bool visited[1001][1001];
void bfs(ll x, ll y)
{
    for (int i = 0; i <= 1001; i++)
    {
        for (int j = 0; j <= 1001; j++)
        {
            trace1[i][j] = -1e18;
            trace2[i][j] = -1e18;
        }
    }
    queue<pii> qu;
    qu.push({x, y});
    while (!qu.empty())
    {
        pii top = qu.front();
        qu.pop();
        if ((trace1[top.fi][top.se] == -1e18))
        {
            for (int k = 0; k < 4; k++)
            {
                ll i1 = top.fi + dx[k];
                ll j1 = top.se + dy[k];
                if ((i1 >= 0) and (i1 <= m) and (j1 >= 0) and (j1 <= n))
                {
                    if (!visited[i1][j1])
                    {
                        qu.push({i1, j1});
                        trace1[i1][j1] = dx[k];
                        trace2[i1][j1] = dy[k];
                    }
                }
            }
        }
        else if (trace1[top.fi][top.se] != -1e18)
        {
            memset(dx, 0, sizeof(dx));
            memset(dx, 0, sizeof(dx));
            //{-1, 0, 1, 0};
            //{0, -1, 0, 1};

            if ((top.fi - trace1[top.fi][top.se] == 1) and (top.se - trace2[top.fi][top.se] == 0))
            {
                ll dx[] = {-1, 0, 0};
                ll dy[] = {0, -1, 1};
                for (int k = 0; k < 3; k++)
                {
                    ll i1 = top.fi + dx[k];
                    ll j1 = top.se + dy[k];
                    if ((i1 >= 0) and (i1 <= m) and (j1 >= 0) and (j1 <= n))
                    {
                        if (!visited[i1][j1])
                        {
                            qu.push({i1, j1});
                            trace1[i1][j1] = dx[k];
                            trace2[i1][j1] = dy[k];
                        }
                        // if ((i1 == s) and (j1 == t))
                        //  return true;
                    }
                }
                cout << dx[0] << ' ';
                return;
            }
        }
    }
}
int main()
{
    
    cin >> m >> n >> x >> y >> s >> t;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            visited[i][j]=false;
        }
    }
    while (cin >> p >> q)
    {
        visited[p][q] = true;
    }
    bfs(x, y);
    cout << trace1[1][0] << ' ' << trace2[0][1];
}