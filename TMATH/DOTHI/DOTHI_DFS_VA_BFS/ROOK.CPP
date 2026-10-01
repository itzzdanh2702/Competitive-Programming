#include <bits/stdc++.h>
using namespace std;

int nx, ny;
vector<int> adj[1000005];
pair<int, int> x, y;
int a[1005][1005];
int path[1005];
int X[1005][1005];
queue<pair<int, int>> Q;

bool check(int u, int v)
{
    return (1 <= u and u <= nx and 1 <= v and v <= nx and a[u][v] == 0);
}

void CAL(int i, int j, int x, int y)
{
    if (check(i, j))
    {
        X[i][j] = X[x][y] + 1;
        Q.push({i, j});
        a[i][j] = 1;
    }
}

int main()
{
    cin >> nx >> ny >> x.first >> x.second >> y.first >> y.second;
    for (int i = 1; i <= nx; i++)
        path[i] = i;
    for (int i = 1; i <= ny; i++)
    {
        int u, v;
        cin >> u >> v;
        a[u][v] = 1;
    }
    Q.push({x.first, x.second});
    a[x.first][x.second] = 1;
    while (!Q.empty())
    {
        auto top = Q.front();
        Q.pop();
        for (int i = 1; i <= nx; i++)
        {
            CAL(top.first, top.second + path[i], top.first, top.second);
            CAL(top.first, top.second - path[i], top.first, top.second);
            CAL(top.first + path[i], top.second, top.first, top.second);
            CAL(top.first - path[i], top.second, top.first, top.second);
        }
    }
    for(int i=1;i<=nx;i++)
    {
        for(int j=1;j<=nx;j++)
            cout<<X[i][j]<<" ";
        cout<<"\n";
    }
}