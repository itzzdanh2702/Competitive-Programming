#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define pii pair<ll, ll>
const long long MOD = 1000000007;
#define MAXN 1000005
#define oo 1000000000
void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int n;

struct matrix
{
    ll x[11][11];
};

matrix a, b, c, d;
int n, p;

matrix nhan(matrix a, matrix b)
{
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            for (int k = 1; k <= n; ++k)
            {
                c.x[i][j] += (a.x[i][k] * b.x[k][j]) % MOD;
                c.x[i][j] %= MOD;
            }
        }
    }
    return c;
}
matrix mu(matrix a, ll n)
{
    if (n == 1)
        return a;
    matrix tmp = mu(a, n / 2);
    matrix tmp1 = nhan(tmp, tmp);
    if (n % 2 == 0)
        return tmp1;
    else
        return nhan(tmp1, a);
}

int main()
{
    FAST();
    cin >> n >> p;
    for (ll i = 1; i <= p; i++)
        for (ll j = 1; j <= p; j++)
            cin >> a.x[i][j];
    d = mu(a, n);
    for(int i = 1 ; i <= p ; ++i)
    {
        for(int j = 1 ; j <= p ; ++j)
        {
            
        }
    }
}
