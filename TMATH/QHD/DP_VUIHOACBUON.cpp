#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1000005
#define oo 1000000000

const ll MOD = pow(2,32);
void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll POW_MAXTRIX, n;

unsigned ll BASE;
unsigned ll a[3][3];
unsigned ll b[3][3];
unsigned ll c[3][3];

void MUL(unsigned ll x[3][3], unsigned ll y[3][3])
{
    unsigned ll tmp[3][3];
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
            unsigned ll res = 0;
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
void POW(unsigned ll a[3][3], unsigned ll n)
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
    cin >> n;
    a[1][1] = 19;
    a[1][2] = 7;
    a[2][1] = 6;
    a[2][2] = 20;
    c[1][1] = 19;
    c[1][2] = 7;
    c[2][1] = 6;
    c[2][2] = 20;
    b[1][1] = 1;
    b[2][1] = 0;
    POW(a, n);
    MUL(a, b);
    cout << a[1][1];
}
// 1 1 2 3 5 8