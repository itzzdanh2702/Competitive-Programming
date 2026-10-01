#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair <int, int>
#define fi first
#define se second

int n, m;
char a[1005][1005];
int d[1005][1005];
pii st, ed;
queue <pii> q;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void bfs(int p1, int p2)
{
    memset(d, -1, sizeof(d));
    d[p1][p2] = 1; 
    q.push({p1, p2});
    while(q.size())
    {
        int i, j;
        tie(i, j) = q.front();
        q.pop();
        for (int t = 0; t <= 3; t++){
            int u = i + dx[t];
            int v = j + dy[t];
            if (u > 0 && u <= n && v > 0 && v <= m && d[u][v] == -1 && a[u][v] == a[i][j]){
                d[u][v] = d[i][j] + 1;
                q.push({u, v});
            }
        }
    }
}

int main()
{
    freopen("FIND.inp","r",stdin);
    freopen("FIND.out","w",stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> a[i][j];
            if (a[i][j] == 'A'){
                st = {i, j};
                a[i][j] = '.';
            }
            else if (a[i][j] == 'B'){
                ed = {i, j};
                a[i][j] = '.';
            }
        }
    }
    bfs(st.fi, st.se);
    if (d[ed.fi][ed.se] > 0) cout << "YES " << d[ed.fi][ed.se] - 1;
    else cout << "NO";
}