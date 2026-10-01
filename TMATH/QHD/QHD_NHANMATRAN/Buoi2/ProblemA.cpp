#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
const ll nmax = 1e6 + 9;
const ll mod = 111539786;
const ll bmax = 3;
ll n, m, p;
int TC;
struct matrix
{
    ll x[bmax][bmax];
};
matrix a, b, c, d, e, f;
matrix nhanmatrix(matrix a, matrix b)
{
    for (ll i = 1; i <= 2; i++)
    {
        for (ll j = 1; j <= 2; j++)
        {
            c.x[i][j] = 0;
            for (ll k = 1; k <= 2; k++)
                c.x[i][j] = (c.x[i][j] + (a.x[i][k] * b.x[k][j]) % mod) % mod;
        }
    }
    return c;
}
matrix mu(matrix a, ll n)
{
    if (n == 1)
        return a;
    matrix tam = mu(a, n / 2);
    tam = nhanmatrix(tam, tam);
    if (n % 2 == 1)
        tam = nhanmatrix(a, tam);
    return tam;
}
int main()
{
    cin >> TC;
    while (TC--)
    {
        cin >> n;
        if (n == 1)
        {
            cout << 1;
            return 0;
        }
        a.x[1][1] = 1;
        a.x[1][2] = 1;
        a.x[2][1] = 1;
        a.x[2][2] = 0;
        f.x[1][1] = 1;
        f.x[2][1] = 1;
        d = mu(a, n - 1);
        e = nhanmatrix(d, f);
        cout << e.x[1][1] << '\n';
    }
}