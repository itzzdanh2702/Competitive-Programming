#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1000005
#define oo 1000000000
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
ll nhanindia(ll a, ll b)
{
    a %= BASE;
    b %= BASE;
    ll t = (long double)a * b / BASE;
    return (a * b - t * BASE) % BASE;
}
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
                res = (res % BASE + nhanindia(x[i][k], y[k][j])) % BASE;
                res %= BASE;
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
    cin >> n >> BASE;
    a[1][1] = 3;
    a[1][2] = 2;
    a[2][1] = 1;
    a[2][2] = 0;
    c[1][1] = 3;
    c[1][2] = 2;
    c[2][1] = 1;
    c[2][2] = 0;
    b[1][1] = 3;
    b[2][1] = 1;
    if (n == 1)
        cout << "1";
    else if (n == 2)
        cout << "3";
    else
    {
        POW(a, n - 1);
        MUL(a, b);
        cout << a[2][1];
    }
}