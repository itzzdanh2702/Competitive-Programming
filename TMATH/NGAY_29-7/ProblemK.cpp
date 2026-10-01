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

int TC;
int k, n;
ll C[MAXN];

ll nhan(ll x, ll y)
{
    return ((x % MOD) * (y % MOD)) % MOD;
}

ll mu(ll a, ll n)
{
    if (n == 0)
        return 1;
    if (n == 1)
        return a;
    ll tmp = mu(a, n / 2);
    if (n & 1)
        return nhan(nhan(tmp, tmp), a);
    else
        return nhan(tmp, tmp);
}
int main(int argc, char const *argv[])
{
    FAST();
    C[0] = 1;
    for (int i = 1; i <= MAXN; ++i)
    {
        C[i] = nhan(C[i - 1], i);
    }
    cin >> TC;
    while (TC--)
    {
        cin >> n >> k;
        cout << nhan(C[n - 1], mu(nhan(C[k - 1], C[n - k]), MOD - 2)) << '\n';
    }
    return 0;
}
