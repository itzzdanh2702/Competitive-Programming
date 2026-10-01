#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nmax 1000000
#define fi first
#define se second
#define pii pair<ll, ll>
ll dx[] = {-1, 0, 1, 0};
ll dy[] = {0, -1, 0, 1};
char a[1001][1001];
ll m, n, ans, dientich, chuvi;
ll ma = 0, kq = 1e9;
bool visited[1001][1001];

void bfs(int u, int v)
{
    queue<pii> qu;
    qu.push({u, v});
    visited[u][v] = true;
    while (!qu.empty())
    {
        pii top = qu.front();
        qu.pop();
        for (int k = 0; k < 4; k++)
        {
            ll i1 = top.fi + dx[k];
            ll j1 = top.se + dy[k];
            if ((i1 >= 1) and (j1 >= 1) and (i1 <= n) and (j1 <= n))
            {
                if ((!visited[i1][j1]) and (a[i1][j1] == '#'))
                {
                    dientich += 1;
                    visited[i1][j1] = true;
                    qu.push({i1, j1});
                }
                else if (a[i1][j1] != '#')
                    chuvi += 1;
            }
            else
                chuvi += 1;
        }
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    memset(visited, false, sizeof(visited));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if ((a[i][j] == '#') and (!visited[i][j]))
            {
                dientich = 1;
                chuvi = 0;
                bfs(i, j);
                if (dientich == ma)
                {
                    kq = min(kq, chuvi);
                }
                else if (dientich > ma)
                {
                    kq = chuvi;
                    ma = dientich;
                }
            }
        }
    }
    cout << ma << ' ' << kq;
}