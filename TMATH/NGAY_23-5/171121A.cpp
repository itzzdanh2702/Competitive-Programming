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

ll n, k;
ll S = 0;
int main()
{
    FAST();
    cin >> n >> k;
    for (ll i = k; i <= n + 1; ++i)
    {
        ll tmp1 = ((i * (i - 1)) / 2) % MOD;
        ll tmp2 = (((2 * n - i + 1) * i) / 2) % MOD;
        S += (tmp2 - tmp1 + 1) % MOD;
        S %= MOD;
    }
    cout << (S + MOD) % MOD;
}