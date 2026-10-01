#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define pii pair<ll, ll>
const long long MOD = 1000000007;
#define MAXN 1000005
#define oo 1000000000
void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int n, m;
int a[MAXN];
int b[MAXN];
int pre[MAXN];
int kq = 0;
int main()
{
   // freopen("D.inp", "r", stdin);
   // freopen("D.out", "w", stdout);
    FAST();
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i)
    {
        pre[i] = pre[i - 1] + a[i];
    }
    for (int i = 1; i <= m; ++i)
    {
        cin >> b[i];
    }
    for (int i = 1; i <= m; ++i)
    {
        int kq = 0;
        int it = upper_bound(a + 1, a + n + 1, b[i]) - a;
        int it1 = lower_bound(a + 1, a + n + 1, b[i]) - a;
        cout << n - it + 1 << ' ';
        int tmp1 = --it1;
        kq += n * tmp1 - pre[tmp1];
        kq += (n - it + 1) * n - (pre[n] - pre[it - 1]) + n - it + 1;
        cout << kq << '\n';
    }
}
