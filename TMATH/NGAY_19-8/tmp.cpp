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

ll store_10[MAXN];
ll store_8[MAXN];
ll store_gt[MAXN];

long long mu(long long a, long long n)
{
    if (n == 0)
        return 1;
    long long tam = mu(a, n / 2);
    tam = (tam * tam) % MOD;
    if (n % 2 == 1)
        tam = (tam * a) % MOD;
    return tam;
}

ll get(ll a, ll b)
{
    return ((a % MOD) * (b % MOD)) % MOD;
}

ll get1(ll a, ll b)
{
    return ((a % MOD) - (b % MOD) + MOD) % MOD;
}

void prepare(ll store[], int k)
{
    store[0] = 1;
    for (int i = 1; i <= MAXN; ++i)
    {
        store[i] = store[i - 1] * k;
        store[i] %= MOD;
    }
}

void prepare1()
{
    store_gt[0] = 1;
    for (int i = 1; i <= MAXN; ++i)
    {
        store_gt[i] = store_gt[i - 1] * i;
        store_gt[i] %= MOD;
    }
}

int n;

int main(int argc, char const *argv[])
{
    FAST();
    prepare(store_10, 10);
    prepare(store_8, 8);
    prepare1();
    ll tmp1 = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        if (i < n)
            tmp1 += get(get(store_gt[n], mu(get(store_gt[n - i], store_gt[i]), MOD - 2)), store_8[n - i]);
        else
        {
            tmp1 += 1;
            tmp1 %= MOD;
        }
    }
    tmp1 *= 2;
    tmp1 %= MOD;
    tmp1 += store_8[n];
    tmp1 %= MOD;
    cout << get1(store_10[n],tmp1);
    return 0;
}
