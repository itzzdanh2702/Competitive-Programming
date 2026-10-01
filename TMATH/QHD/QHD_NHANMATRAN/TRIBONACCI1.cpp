#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000009
#define MAXN 1000005
#define oo 1000000000
void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll POW_MAXTRIX, n;

unsigned ll a[4][4];
unsigned ll b[4][4];
unsigned ll c[4][4];

void MUL(unsigned ll x[4][4], unsigned ll y[4][4])
{
    unsigned ll tmp[4][4];
    for (int i = 1; i <= 3; ++i)
    {
        for (int j = 1; j <= 3; ++j)
        {
            tmp[i][j] = 0;
        }
    }
    for (int i = 1; i <= 3; ++i)
    {
        for (int j = 1; j <= 3; ++j)
        {
            unsigned ll res = 0;
            for (int k = 1; k <= 3; ++k)
            {
                res += ((x[i][k] % MOD) * (y[k][j] % MOD)) % MOD;
                res %= MOD;
            }
            tmp[i][j] = res;
        }
    }
    for (int i = 1; i <= 3; ++i)
    {
        for (int j = 1; j <= 3; ++j)
        {
            a[i][j] = tmp[i][j];
        }
    }
}
void POW(unsigned ll a[4][4], unsigned ll n)
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

    while (cin >> n)
    {
        a[1][1] = 1;
        a[1][2] = 1;
        a[1][3] = 1;
        a[2][1] = 1;
        a[2][2] = 0;
        a[2][3] = 0;
        a[3][1] = 0;
        a[3][2] = 1;
        c[1][1] = 1; //
        c[1][2] = 1;
        c[1][3] = 1;
        c[2][1] = 1;
        c[2][2] = 0;
        c[2][3] = 0;
        c[3][1] = 0;
        c[3][2] = 1;
        c[3][3] = 0;
        b[1][1] = 2;
        b[2][1] = 1;
        b[3][1] = 0;
        if (n == 0)
        {
            cout << "\n";
            return 0;
        }
        else if (n == 1)
        {
            cout << "0" << '\n';
        }
        else if (n == 2)
        {
            cout << "1" << '\n';
        }
        else if (n == 3)
        {
            cout << "2" << '\n';
        }
        else
        {
            POW(a, n - 3);
            MUL(a, b);
            cout << a[1][1] << '\n';
        }
    }
}