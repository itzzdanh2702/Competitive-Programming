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
int a[1005][1005];
bool check[1005][1005];
bool ok = 1;
int cnt = 0, cnt1 = 0;

int main()
{
    //freopen("XOANOC.inp", "r", stdin);
    //freopen("XOANOC.out", "w", stdout);
    FAST();
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            cin >> a[i][j];
        }
    }
    // 1,1 --> 1,m --> n,m --> n,1 --> 1,1
    int tmp = n;
    int tmp1 = m;
    while (ok)
    {
        ++cnt;
        if (cnt % 4 == 1)
        {
            for (int i = m - tmp1 + 1; i <= tmp1; ++i)
            {
                if (!check[n - tmp + 1][i])
                {
                    cout << a[n - tmp + 1][i] << ' ';
                    ++cnt1;
                }
                check[n - tmp + 1][i] = 1;
            }
        }
        else if (cnt % 4 == 2)
        {
            for (int i = n - tmp + 2; i <= tmp; ++i)
            {
                if (!check[i][tmp1])
                {
                    cout << a[i][tmp1] << ' ';
                    ++cnt1;
                }
                check[i][tmp1] = 1;
            }
        }
        else if (cnt % 4 == 3)
        {
            for (int i = tmp1 - 1; i >= m - tmp1 + 1; --i)
            {
                if (!check[tmp][i])
                {
                    cout << a[tmp][i] << ' ';
                    ++cnt1;
                }
                check[tmp][i] = 1;
            }
        }
        else
        {
            for (int i = tmp - 1; i >= n - tmp + 2; --i)
            {
                if (!check[i][m - tmp1 + 1])
                {
                    cout << a[i][m - tmp1 + 1] << ' ';
                    ++cnt1;
                }
                check[i][m - tmp1 + 1] = 1;
            }
            --tmp;
            --tmp1;
        }
        if (cnt1 == m * n)
            exit(0);
    }
}
