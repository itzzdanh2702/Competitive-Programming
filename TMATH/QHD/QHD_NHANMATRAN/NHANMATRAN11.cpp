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
ll a[4][4];
ll b[4][4];
ll c[4][4];
ll TC;

void MUL(ll x[4][4], ll y[4][4])
{
    ll tmp[4][4];
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
            ll res = 0;
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
void POW(ll a[4][4], ll n)
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
    if(n == 1)
    cout << "1";
    else 
    {
    a[1][1] = 1;
    a[1][2] = 1;
    a[1][3] = 1;
    a[2][1] = 0;
    a[2][2] = 1;
    a[2][3] = 1;
    a[3][1] = 0;
    a[3][2] = 1;
    a[3][3] = 0; //
    c[1][1] = 1;
    c[1][2] = 1;
    c[1][3] = 1;
    c[2][1] = 0;
    c[2][2] = 1;
    c[2][3] = 1;
    c[3][1] = 0;
    c[3][2] = 1;
    c[3][3] = 0;
    b[1][1] = 2;
    b[2][1] = 1;
    b[3][1] = 1;
    POW(a, n - 2);
    MUL(a, b);
    cout << a[1][1];
    }
}
