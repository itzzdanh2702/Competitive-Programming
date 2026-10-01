#include <bits/stdc++.h>
using namespace std;
#define ll long long
const long long MOD = 1000000007;
#define MAXN 1000005
#define oo 1000000000
void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll POW_MAXTRIX, n;
ll a[15][15];
ll b[15][15];
ll c[15][15];

void MUL(long long x[15][15], long long y[15][15])
{
    ll tmp[10][10];
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            long long res = 0;
            for (int k = 1; k <= n; ++k)
            {
                res += (x[i][k] * y[k][j]) % MOD;
                res %= MOD;
            }
            tmp[i][j] = res;
        }
    }
    for(int i = 1 ; i <= n ; ++i)
    {
        for(int j = 1 ; j <= n ; ++j)
        {
            a[i][j] = tmp[i][j];
        }
    }
}

void pow_maxtrix(long long a[15][15], ll n)
{
    if (n <= 1)
        return;
    pow_maxtrix(a, n / 2);
    MUL(a, a);
    if (n & 1)
        MUL(a,b);
}

int main()
{
    cin >> POW_MAXTRIX >> n;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cin >> a[i][j];
            b[i][j] = a[i][j];
        }
    }
    pow_maxtrix(a,POW_MAXTRIX);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
}