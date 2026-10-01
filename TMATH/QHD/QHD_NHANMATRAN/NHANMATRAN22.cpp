#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1000005
#define oo 1000000000
const ll MOD = 1e9 + 7;
void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll POW_MAXTRIX, n;

unsigned ll a[5][5];
unsigned ll b[5][5];
unsigned ll c[5][5];
ll TC;
ll m, n, p, q, N;

void MUL(unsigned ll x[5][5], unsigned ll y[5][5])
{
    unsigned ll tmp[5][5];
    for (int i = 1; i <= 4; ++i)
    {
        for (int j = 1; j <= 4; ++j)
        {
            tmp[i][j] = 0;
        }
    }
    for (int i = 1; i <= 4; ++i)
    {
        for (int j = 1; j <= 4; ++j)
        {
            unsigned ll res = 0;
            for (int k = 1; k <= 4; ++k)
            {
                res += ((x[i][k] % MOD) * (y[k][j] % MOD)) % MOD;
                res %= MOD;
            }
            tmp[i][j] = res;
        }
    }
    for (int i = 1; i <= 4; ++i)
    {
        for (int j = 1; j <= 4; ++j)
        {
            a[i][j] = tmp[i][j];
        }
    }
}
void POW(unsigned ll a[5][5], unsigned ll n)
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
    cin >> m >> n >> p >> q >> N;
    a[1][1] = m * m, a[1][2] = n * n, a[1][3] = 2 * m * n, a[1][4] = 0;
    a[2][1] = p * p, a[2][1] = q * q, a[2][1] = 2 * p * q, a[2][1] = 0;
    a[3][1] = m * p, a[3][2] = n * q, a[3][3] = m * q + n * p, a[3][4] = 0;
    a[4][1] = m * p, a[4][2] = n * q, a[4][3] = m * q + n * p, a[4][4] = 1;

    a[1][1] = m * m, a[1][2] = n * n, a[1][3] = 2 * m * n, a[1][4] = 0;
    a[2][1] = p * p, a[2][1] = q * q, a[2][1] = 2 * p * q, a[2][1] = 0;
    a[3][1] = m * p, a[3][2] = n * q, a[3][3] = m * q + n * p, a[3][4] = 0;
    a[4][1] = m * p, a[4][2] = n * q, a[4][3] = m * q + n * p, a[4][4] = 1;

    c[1][1] = 1, c[2][1] = 4, c[3][1] = 2, c[4][1] = 5;

    POW(a, n - 1);
    MUL(a, c);

    cout << c[4][1];
}
/*
Sn = Sn-1 + An-1^2
An^2 = 4.An-1^2 + An-2^2 + 4.An-1.An-2
An.An-1 = (2.An-1 + An-2).An-1 = 2.An-1^2 + An-1.An-2
[An^2]
[An-1^2]
[An.An-1]
[Sn-1]
An^2 = A11.An-1^2 + A12.An-2^2 + A13.An-1.An-2 + A14.Sn-2
An-1^2 = A21.An-1^2 + A22.An-2^2 + A23.An-1.An-2 + A24.Sn-2
An.An-1 = A31.An-1^2 + A32.An-2^2 + A33.An-1.An-2 + A34.Sn-2
Sn-1 = A41.An-1^2 + A42.An-2^2 + A43.An-1.An-2 + A44.Sn-2
[4 1 4 0]
[1 0 0 0]
[2 0 1 0]
[1 0 0 1]
*/
