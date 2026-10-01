#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nmax 1000000
const ll INF = 1e9;
ll a[1001][1001];
ll t;
ll n, m;
ll u, v, w;
ll ans[nmax];
ll kq = INF;
ll mi = INF;
int kq1 = INF;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            a[i][j] = INF;
        }
    }
    while (cin >> u >> v >> w)
    {
        a[u][v] = a[v][u] = w;
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
                        mi = min(mi,a[i][j]);
                    }
                }
            }
        }
    }
    cout<<mi;
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i][j] != 0 and (a[i][j] != INF))
            {
                ans[i] = max(ans[i], a[i][j]);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (kq > ans[i])
        {
            kq = ans[i];
            kq1 = i;
        }
        else if (kq == ans[i])
        {
            kq1 = min(kq1,i);
        }
    }
    cout << kq << ' ' << kq1;
  

}
