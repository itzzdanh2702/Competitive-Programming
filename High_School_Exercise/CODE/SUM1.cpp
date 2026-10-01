#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll const nmax = 1e6 + 6;
ll const mod = 1e9 + 7;

ll n, x, a[nmax], f[nmax];

int main()
{
    // freopen("SUM1.inp","r",stdin);
    // freopen("SUM1.out","w",stdout);
    cin >> n >> x;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1, greater<ll>());
    f[0] = 1;
    for (int i = 1; i <= x; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            ll ans = i - a[j];
            if (ans >= 0)
            {
                if()
                f[i] = (f[i] + f[ans]) % mod;
            }
        }
    }
    cout << f[x];
}
