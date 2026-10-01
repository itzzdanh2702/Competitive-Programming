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
ll a[6][6];
ll b[6][6];
ll c[6][6];
ll TC;

void MUL(ll x[6][6], ll y[6][6])
{
    ll tmp[6][6];
    for (int i = 1; i <= 5; ++i)
    {
        for (int j = 1; j <= 5; ++j)
        {
            tmp[i][j] = 0;
        }
    }
    for (int i = 1; i <= 5; ++i)
    {
        for (int j = 1; j <= 5; ++j)
        {
            ll res = 0;
            for (int k = 1; k <= 5; ++k)
            {
                res += ((x[i][k] % MOD) * (y[k][j] % MOD)) % MOD;
                res %= MOD;
            }
            tmp[i][j] = res;
        }
    }
    for (int i = 1; i <= 5; ++i)
    {
        for (int j = 1; j <= 5; ++j)
        {
            a[i][j] = tmp[i][j];
        }
    }
}
void POW(ll a[6][6], ll n)
{
    if (n <= 1)
        return;
    POW(a, n / 2);
    MUL(a, a);
    if (n & 1)
        MUL(a, b);
}
int main()
{
    cin >> TC;
    while (TC--)
    {
        cin >> n;
        if (n == 1)
        {
            cout << "1" << '\n';
        }
        else if (n == 2)
        {
            cout << "7" << '\n';
        }
        else
        {
            a[1][1] = 3, a[1][2] = -2, a[1][3] = 0, a[1][4] = 0, a[1][5] = 0;
            a[2][1] = 1, a[2][2] = 0, a[2][3] = 0, a[2][4] = 0, a[2][5] = 0;
            a[3][1] = 0, a[3][2] = 0, a[3][3] = 0, a[3][4] = 1, a[3][5] = 0;
            a[4][1] = 3, a[4][2] = -4, a[4][3] = -2, a[4][4] = 3, a[4][5] = 0;
            a[5][1] = 3, a[5][2] = -4, a[5][3] = -2, a[5][4] = 3, a[5][5] = 1;

            b[1][1] = 3, b[1][2] = -2, b[1][3] = 0, b[1][4] = 0, b[1][5] = 0;
            b[2][1] = 1, b[2][2] = 0, b[2][3] = 0, b[2][4] = 0, b[2][5] = 0;
            b[3][1] = 0, b[3][2] = 0, b[3][3] = 0, b[3][4] = 1, b[3][5] = 0;
            b[4][1] = 3, b[4][2] = -4, b[4][3] = -2, b[4][4] = 3, b[4][5] = 0;
            b[5][1] = 3, b[5][2] = -4, b[5][3] = -2, b[5][4] = 3, b[5][5] = 1;

            c[1][1] = 3, c[2][1] = 1, c[3][1] = 1, c[4][1] = 6, c[5][1] = 7;

            POW(a, n - 2);
            MUL(a, c);
            cout << (a[5][1] + MOD) % MOD << '\n';
        }
    }
}

