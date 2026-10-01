#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nmax 1000000
#define fi first
#define se second
#define pii pair<ll, ll>
ll dx[] = {-1, 0, 1, 0};
ll dy[] = {0, -1, 0, 1};
ll a[1001][1001];
ll b[1001][1001], c[1001][1001];
ll m, n, u, v;

void bfs(int u, int v)
{
    queue<pii> qu;
    b[u][v] = 1;
    c[u][v] = 1;
    qu.push({u, v});
    pii top = qu.front();
    qu.pop();
    for (int k = 0; k < 4; k++)
    {
        ll i1 = top.fi + dx[k];
        ll j1 = top.se + dy[k];
        if ((i1 >= 1) and (j1 >= 1) and (i1 <= m) and (j1 <= n))
        {
            if (a[i1][j1] == a[top.fi][top.se])
            {
                b[i1][j1] = 0;
                c[i1][j1] = 0;
            }
            else if (a[i1][j1] < a[top.fi][top.se])
            {
                b[i1][j1] = 1;
                // b[i][j] luu o cao xuong thap
                // c[i1][j1]=1e18;
            }
            else if (a[i1][j1] > a[top.fi][top.se])
            {
                c[i1][j1] = 1;
                // c[i][j] luu o thap len cao
                // b[i1][j1] = 1e18;
            }
            qu.push({i1, j1});
        }
    }
    while (!qu.empty())
    {
        pii tmp = qu.front();
        qu.pop();
        for (int k = 0; k < 4; k++)
        {
            ll x1 = tmp.fi + dx[k];
            ll y1 = tmp.se + dy[k];
            if ((x1>= 1) and (x1 <= m) and (y1 >= 1) and (y1 <= n))
            {
                if ((a[x1][y1] < a[tmp.fi][tmp.se]) and (b[x1][y1] > c[tmp.fi][tmp.se] + 1))
                {
                    b[x1][y1] = c[tmp.fi][tmp.se] + 1;
                    qu.push({x1, y1});
                }
                else if ((a[x1][y1] > a[tmp.fi][tmp.se]) and (c[x1][y1] > b[tmp.fi][tmp.se] + 1))
                {
                    c[x1][y1] = b[tmp.fi][tmp.se] + 1;
                    qu.push({x1, y1});
                }
                else if (a[x1][y1] == a[tmp.fi][tmp.se])
                {
                    ll dem = 0;
                    if (b[x1][y1] > b[tmp.fi][tmp.se])
                    {
                        dem++;
                        b[x1][y1] = b[tmp.fi][tmp.se];
                        qu.push({x1, y1});
                    }
                    else if (c[x1][y1] > c[tmp.fi][tmp.se])
                    {
                        c[x1][y1] = c[tmp.fi][tmp.se];
                        if (dem == 0)
                            qu.push({x1, y1});
                    }
                }
            }
        }
    }
}
int main()
{
    cin >> m >> n >> u >> v;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            b[i][j] = 1e18;
            c[i][j] = 1e18;
        }
    }
    bfs(u, v);
    b[u][v]=c[u][v]=0;
    if((b[m][n]!=1e18) and (c[m][n]==1e18))
    cout<<b[m][n];
    else if((b[m][n]==1e18) and (c[m][n]!=1e18))
    cout<<c[m][n];
    else if((b[m][n]!=1e18) and (c[m][n]!=1e18))
    cout<<min(c[m][n],b[m][n]);
    else cout<<"-1";
}