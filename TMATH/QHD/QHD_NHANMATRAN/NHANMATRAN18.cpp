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

 ll a[5][5];
 ll b[5][5];
 ll c[5][5];
ll TC;

void MUL( ll x[5][5],  ll y[5][5])
{
     ll tmp[5][5];
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
void POW( ll a[5][5],  ll n)
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
    cin >> n;
    if(n == 1) 
    {
        cout << "1";
        return 0;
    }
    a[1][1] = 0, a[1][2] = 1, a[1][3] = 0, a[1][4] = 0;
    a[2][1] = 1, a[2][2] = 4, a[2][3] = 4, a[2][4] = 0;
    a[3][1] = 0, a[3][2] = 2, a[3][3] = 1, a[3][4] = 0;
    a[4][1] = 1, a[4][2] = 4, a[4][3] = 4, a[4][4] = 1;

    b[1][1] = 0, b[1][2] = 1, b[1][3] = 0, b[1][4] = 0;
    b[2][1] = 1, b[2][2] = 4, b[2][3] = 4, b[2][4] = 0;
    b[3][1] = 0, b[3][2] = 2, b[3][3] = 1, b[3][4] = 0;
    b[4][1] = 1, b[4][2] = 4, b[4][3] = 4, b[4][4] = 1;

    c[1][1] = 1, c[2][1] = 4, c[3][1] = 2, c[4][1] = 5;

    POW(a, n - 2);  
    MUL(a, c);

    cout << a[4][1];
}
