#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll const nmax = 1e6 + 5;
ll const mod = 1e9 + 7;

ll n, m, a[nmax], b[nmax], f[nmax], res = 0;

int main()
{
    freopen("BUS.inp", "r", stdin);
    freopen("BUS.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    for (int i = 1; i <= m; i++)
        f[i] = 1e18;
    int i = 0;
    while (i < m || f[i] == 1e18)
    {
        i++;
        for (int j = 1; j <= n; j++)
        {
            if (i - b[j] >= 0)
                f[i] = min(f[i], f[i - b[j]] + a[j]);
        }
    }
    cout << f[i];
}
