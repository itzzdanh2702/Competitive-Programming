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
ll BASE;
ll a[3][3];
ll b[3][3];
ll c[3][3];
ll TC;

void MUL(ll x[3][3], ll y[3][3])
{
    ll tmp[3][3];
    for (int i = 1; i <= 2; ++i)
    {
        for (int j = 1; j <= 2; ++j)
        {
            tmp[i][j] = 0;
        }
    }
    for (int i = 1; i <= 2; ++i)
    {
        for (int j = 1; j <= 2; ++j)
        {
            ll res = 0;
            for (int k = 1; k <= 2; ++k)
            {
                res += ((x[i][k] % MOD) * (y[k][j] % MOD)) % MOD;
                res %= MOD;
            }
            tmp[i][j] = res;
        }
    }
    for (int i = 1; i <= 2; ++i)
    {
        for (int j = 1; j <= 2; ++j)
        {
            a[i][j] = tmp[i][j];
        }
    }
}

void POW(ll a[3][3], ll n)
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
    FAST();
    cin >> TC;
    while (TC--)
    {
        cin >> n;
        a[1][1] = 3;
        a[1][2] = -2;
        a[2][1] = 1;
        a[2][2] = 0;
        c[1][1] = 3;
        c[1][2] = -2;
        c[2][1] = 1;
        c[2][2] = 0;
        b[1][1] = 3;
        b[2][1] = 1;
        if (n == 1)
            cout << "1" << '\n';
        else if (n == 2)
            cout << "3" << '\n';
        else
        {
            POW(a, n - 1);
            MUL(a, b);
            cout << (a[2][1] + MOD) % MOD  << '\n';
        }
    }
}