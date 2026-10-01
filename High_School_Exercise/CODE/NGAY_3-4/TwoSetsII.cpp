#include <bits/stdc++.h>
using namespace std;
#define ll long long
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
ll f[70000];
ll tmp;
ll sum = 0;
long long power_mod(long long a, long long b, long long MOD)
{
    if (b == 0)
        return 1;
    if (b == 1)
        return a;

    long long half = power_mod(a, b / 2, MOD) % MOD;

    if (b % 2 == 0)
        return (half * half) % MOD;
    else
        return (((half * half) % MOD) * a) % MOD;
}

int main()
{
    FAST();
    cin >> n;
    sum = n * (n + 1) / 2;
    tmp = (n * (n + 1)) / 4;
    if (sum % 2 == 1)
    {
        cout << "0";
        return 0;
    }
    f[0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = tmp; j >= i; --j)
        {
            f[j] = (f[j] + f[j - i]);
            f[j] %= MOD;
        }
    }
    cout << ((f[tmp] % MOD) * power_mod(2, MOD - 2, MOD)) % MOD;
}