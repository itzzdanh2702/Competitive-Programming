#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
int n, m, u, x, y, x2, y2, mi = 100000, trace[1001][1001], dem = 0;

vector<ll> v[1001];
vector<pair<int, int>> p;

bool visited[1001][1001];
ll a[1001][1001];
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

int d[1001][1001];

void bfs1(int i, int j)
{
    queue<pair<int, int>> q;
    q.push({i, j});
    d[i][j] = 0;
    visited[i][j] = true;
    dem++;
    cout << i << ' ' << j << endl;
    while (!q.empty())
    {
        pair<int, int> top = q.front();
        q.pop();
        for (int k = 0; k < 4; k++)
        {
            int i1 = top.fi + dx[k];
            int j1 = top.se + dy[k];
            if (i1 >= 1 && i1 <= m && j1 >= 1 && j1 <= n && !visited[i1][j1])
            {
                dem++;
                if ((a[i1][j1] < a[top.fi][top.se]) and (dem % 2 == 0))
                {
                    q.push({i1, j1});
                    visited[i1][j1] = true;
                    cout << i1 << ' ' << j1 << endl;
                }
                else if ((a[i1][j1] > a[top.fi][top.se]) and (dem % 2 == 1))
                {
                    q.push({i1, j1});
                    visited[i1][j1] = true;
                    cout << i1 << ' ' << j1 << endl;
                }
            }
        }
    }
}

int main()
{
    cin >> m >> n >> x >> y;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    visited[1][3] = true;
    bfs1(2, 3);
}
