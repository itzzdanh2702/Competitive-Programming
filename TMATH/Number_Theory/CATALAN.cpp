#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
long long F[200005];
long long mu(long long a, long long n)
{
    if (n == 0)
        return 1;
    long long tam = mu(a, n / 2);
    tam = (tam * tam) % mod;
    if (n % 2 == 1)
        tam = (tam * a) % mod;
    return tam;
}
long long mul(ll x, ll y)
{
    return ((x % mod) * (y % mod)) % mod;
}
int main()
{
    long long a, n;
    F[0] = 1;
    for (int i = 1; i <= 200001; i++)
    {
        F[i] = mul(F[i - 1], i);
    }
    cin >> a;
    while (a--)
    {
        cin >> n;
        cout << mul(F[2 * n], mu(mul(F[n], F[n + 1]), mod - 2)) << "\n";
    }
}
