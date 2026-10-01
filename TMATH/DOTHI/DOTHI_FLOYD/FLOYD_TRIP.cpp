#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nmax 1000000
const ll INF = 1e18;
ll a[1001][1001];
ll t;
ll n, m;
ll maxa;
ll S;
ll kq, ans;
ll mi = INF;
ll h=1;
bool check[nmax];
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            a[i][j] = INF;
        }
    }
    while (m--)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        a[u][v] = w;
        a[v][u] = w;
    }
    for (int i = 1; i <= n; i++)
        a[i][i] = 0;
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if ((a[i][k] != 0) and (a[k][j] != 0) and (a[i][k] != INF) and (a[k][j] != INF))
                {
                    if (a[i][j] > a[i][k] + a[k][j])
                    {
                        a[i][j] = a[i][k] + a[k][j];
                    }
                }
            }
        }
    }
   
    while (check[h] == 0)
    {
        check[h] = 1;
        ll max1 = 1e9, max2 = 0;
        for (int i = 2; i <= n - 1; i++)
        {
            if ((max1 > a[h][i]) and (check[i] == 0))
            {
                max1 = a[h][i];
                max2 = i;
            }
        }
        if (max1 == 1e9)
            break;
        kq += a[h][max2];
        h = max2;
    }
    kq += a[h][n];
    cout << kq;
}
