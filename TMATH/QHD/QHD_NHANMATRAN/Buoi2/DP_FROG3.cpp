#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1000005
#define oo 1000000000

const ll MOD = 998244353;
void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll POW_MAXTRIX, n;
int k;
int cnt = 0;
int dp[MAXN];
unsigned ll a[101][101];
unsigned ll b[101][101];
unsigned ll c[101][102];
unsigned ll d[101][102];

void MUL(unsigned ll x[102][102], unsigned ll y[102][102])
{
    unsigned ll tmp[102][102];
    for (int i = 1; i <= 101; ++i)
    {
        for (int j = 1; j <= 101; ++j)
        {
            tmp[i][j] = 0;
        }
    }
    for (int i = 1; i <= 101; ++i)
    {
        for (int j = 1; j <= 101; ++j)
        {
            unsigned ll res = 0;
            for (int k = 1; k <= 101; ++k)
            {
                tmp[i][j] += ((x[i][k] % MOD) * (y[k][j] % MOD)) % MOD;
                res %= MOD;
            }
        }
    }
    for (int i = 1; i <= 101; ++i)
    {
        for (int j = 1; j <= 101; ++j)
        {
            a[i][j] = tmp[i][j];
        }
    }
}
void POW(unsigned ll a[102][102], unsigned ll n)
{
    if (n <= 1)
        return;
    POW(a, n / 2);
    MUL(a, a);
    if (n & 1)
        MUL(a, c);
}
int main()
{
    cin >> n >> k;
    for (int i = 1; i <= k; ++i)
    {
        for (int j = 1; j <= k; ++j)
        {
            if (i == j)
            {
                a[i][j] = 1;
            }
        }
    }
    for (int i = 1; i <= k; ++i)
    {
        a[k + 1][i] = 1;
    }
    for (int i = 1; i <= k + 1; ++i)
    {
        for (int j = 1; j <= k + 1; ++j)
        {
            if (i - j >= 0)
            {
                dp[i] += (dp[i - j] % MOD);
            }
            ++cnt;
            d[cnt][1] = dp[i];
        }
    }

    POW(a, n - 1);
    MUL(a, b);
    cout << ((a[1][1] % MOD) * (a[2][1] % MOD)) % MOD;
}
// 1 1 2 3 5 8

/*
    g(n)
    1
    1
    1
    1
    1
*/
