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
ll ma, mi;
ll a[105][105];
int main()
{
    FAST();
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (i == 1)
            {
                if (j == 1)
                {
                    a[i][j] = 1;
                }
                else if (j == n)
                {
                    if (a[i + 1][j] == -1)
                    {
                        a[i][j] = a[i][j - 1];
                    }
                    else
                    {
                        ma = a[i][j - 1];
                        mi = a[i + 1][j];
                        if (ma > mi)
                        {
                            cout << "-1";
                            return 0;
                        }
                    }
                }
                else
                {
                    if ((a[i + 1][j] == -1) and (a[i][j + 1] != -1))
                    {
                        mi = a[i][j + 1];
                    }
                    else if ((a[i + 1][j] != -1) and (a[i][j + 1] == -1))
                    {
                        mi = a[i + 1][j];
                    }
                    else
                    {
                        a[i][j] = a[i][j - 1];
                        continue;
                    }
                    if (mi < ma)
                    {
                        cout << "-1";
                        return 0;
                    }
                    a[i][j] = a[i][j - 1];
                }
            }
            if (j == 1)
            {
                if (i == n)
                {
                    ma = a[i - 1][j];
                    if (a[i][j + 1] == -1)
                    {
                        a[i][j] = a[i - 1][j];
                    }
                    else
                    {
                        mi = a[i][j + 1];
                    }
                    if (ma > mi)
                    {
                        cout << "-1";
                        return 0;
                    }
                    a[i][j] = a[i - 1][j];
                }
                else
                {
                    ma = a[i - 1][j];
                    if ((a[i + 1][j] == -1) and (a[i][j + 1] != -1))
                    {
                        mi = a[i][j + 1];
                    }
                    else if ((a[i + 1][j] != -1) and (a[i][j + 1] == -1))
                    {
                        mi = a[i + 1][j];
                    }
                    else
                    {
                        a[i][j] = a[i][j - 1];
                        continue;
                    }
                    if (mi < ma)
                    {
                        cout << "-1";
                        return 0;
                    }
                    a[i][j] = a[i - 1][j];
                }
            }
            if (i == n)
            {
                if (j == n)
                {
                    a[i][j] = min(a[i - 1][j], a[i][j - 1]);
                }
                else
                {
                    if ((a[i + 1][j] == -1) and (a[i][j + 1] != -1))
                    {
                        mi = a[i][j + 1];
                    }
                    else if ((a[i + 1][j] != -1) and (a[i][j + 1] == -1))
                    {
                        mi = a[i + 1][j];
                    }
                    else
                    {
                        a[i][j] = a[i][j - 1];
                        continue;
                    }
                    if (mi < ma)
                    {
                        cout << "-1";
                        return 0;
                    }
                    a[i][j] = a[i][j - 1];
                }
            }
        }
        ma = max(a[i - 1][j], a[i][j - 1]);
        mi = min(a[i + 1][j], a[i][j + 1]);
        if (mi <)
    }
}
}