#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nmax 1000000
ll a[nmax], n, f[nmax], k, g[nmax], s[nmax], ans;

ll mod(ll a, ll base)
{
    return ((a % base) + base) % base;
}
int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = 1; i <= n; i++)
    {
        s[i] = s[i - 1] + a[i];
        f[i] = mod(s[i], k);
    }

    for (int i = 1; i <= n; i++)
    {
        g[f[i]]++;
    }
    for (int i = 0; i <= k - 1; i++)
    {
        if (i != 0)
            ans += (g[i] * (g[i] - 1)) / 2;
        else
        {
            ans += g[i];
            ans += (g[i] * (g[i] - 1)) / 2;
        }
    }
    cout << ans;
}
