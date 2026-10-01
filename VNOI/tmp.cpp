#include <bits/stdc++.h>

#define MAXN 3000005

using namespace std;

int n, x;
int a[MAXN];
long long f[MAXN][4], ans;

int main()
{
    cin >> n >> x;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
    {
        f[i][1] = max(f[i - 1][1] + a[i], 0ll);
        f[i][2] = max(f[i - 1][2], f[i - 1][1]) + 1ll * a[i] * x;
        f[i][3] = max(f[i - 1][3], f[i - 1][2]) + a[i];
        ans = max(ans, max(f[i][1], max(f[i][2], f[i][3])));
        cout << ans << ' ';
    }
    cout << ans << endl;
}
