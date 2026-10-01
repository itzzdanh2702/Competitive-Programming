#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
int n, m, u, x, y, x2, y2, mi = 100000;
vector<ll> v[1001];
bool visited[1001][1001];
char a[1001][1001];
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
int d[1001][1001];
vector<pair<int, int>> p;

void bfs(int i, int j)
{
    queue<pair<int, int>> q;
    q.push({i, j});
    d[i][j] = 0;
    visited[i][j] = true;
    while (!q.empty())
    {
        pair<int, int> top = q.front();
        q.pop();
        for (int k = 0; k < 4; k++)
        {
            int i1 = top.first + dx[k];
            int j1 = top.second + dy[k];
            if (i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m && a[i1][j1] != 'X' && !visited[i1][j1])
            {
                d[i1][j1] = d[top.first][top.second] + 1;
                if (a[i1][j1] == 'E')
                    return;
                q.push({i1, j1});
                visited[i1][j1] = true;
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == 'E')
            {
                x = i;
                y = j;
            }
            if (a[i][j] == '.' and (i == 1 or j == 1))
            {
                p.push_back({i, j});
            }
            if (a[i][j] == '.' and (i == n or j == m))
            {
                p.push_back({i, j});
            }
        }
    }
    if (p.size() == 0)
    {
        return cout << -1, 0;
    }
    int dem = 0;
    for (int i = 0; i < p.size(); i++)
    {
        memset(visited, false, sizeof(visited));
        memset(d, 0, sizeof(d));
        bfs(p[i].fi, p[i].se);
        if (!d[x][y])
        {
            dem++;
        }
        else
        {
            mi = min(mi, d[x][y]);
        }
    }
    if (dem == p.size())
        cout << -1;
    else
        cout << mi;
}