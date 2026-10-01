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

long n, m;
ll cnt = 0;
void input()
{
    cin >> n >> m;
    long a[n][m];
    long h[min(n, m)][max(n, m)];
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> a[i][j];
        }
    }
    if (n > m)
    {
        swap(m, n);
        // bay gio m se lon hon
        /*
           1 1 1
           1 1 1    1 1 1 1
           1 1 1    1 1 1 1
           1 1 1    1 1 1 1
        */
        for (long i = 0; i < n; ++i)
        {
            for (long j = m - 1; j >= 0; --j)
            {
                h[i][m - j - 1] = a[j][i];
            }
        }
    }
    else
    {
        for (long i = 0; i < n; ++i)
        {
            for (long j = 0; j < m; ++j)
            {
                h[i][j] = a[i][j];
            }
        }
    }
    for (long i1 = 0; i1 < n; ++i1)
        for (int i2 = i1 + 1; i2 < n; ++i2)
        {
            vector<long> down(m), up(m);
            for (long j = 0; j < m; ++j)
            {
                if (h[i1][j] >= i2 - i1)
                    down[j] = true;
                if (h[i2][j] >= i2 - i1)
                    up[j] = true;
            }
            for (long j1 = 0; j1 < m; ++j1)
            {
                if (!up[j1])
                    continue;
                for (long j2 = j1 + 1; j2 < min(m, j1 + h[i1][j1] + 1); ++j2)
                    cnt += ((down[j2]) && (h[i2][j2] >= (j2 - j1)));
            }
        }
    cout << cnt;
}

int main()
{
    FAST();
    input();
}