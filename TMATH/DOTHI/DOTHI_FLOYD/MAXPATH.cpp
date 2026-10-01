#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nmax 1005
ll n, m, d[nmax][nmax];
ll u, v, w;
int main()
{
    memset(d, 0x3f, sizeof(d));
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v >> w;
        d[u][v] = d[v][u] = w;
    }
    for (int i = 1; i <= n; i++)
        d[i][i] = 0;
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    }
    for (int i = 1; i <= n; i++)
    {
        ll maxa = -1;
        for (int j = 1; j <= n; j++)
            maxa = max(maxa, d[i][j]);
        cout << maxa << endl;
    }
}