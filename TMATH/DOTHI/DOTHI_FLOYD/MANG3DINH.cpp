#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nmax 1000000
const ll INF = 1e18;
ll a[1001][1001];
ll t;
ll n, m;
ll ans = 1e9;
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
     for (int i = 1; i <= n; i++)
        a[i][i] = 0;
    while (m--)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        a[u][v] = min(a[u][v],w);
        a[v][u] = min(a[v][u],w);
    }
   
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
    for(int i=1;i<=n;i++)
    {
        ans = min(ans,a[i][1]+a[i][2]+a[i][3]);
    }
    cout<<ans;
}
