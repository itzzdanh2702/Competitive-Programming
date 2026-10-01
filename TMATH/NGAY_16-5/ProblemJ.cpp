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
ll legendere(ll n, int k)
{
    ll dem = 0;
    while (n > 0)
    {
        dem += n / k;
        dem %= MOD;
        n /= k;
    }
    return dem;
}

ll a, b;
int TC;

int main()
{
    FAST();
    cin >> TC;
    while (TC--)
    {
        cin >> a >> b;
        ll tmp  = legendere(a - 1, 2);
        ll tmp1 = legendere(a - 1, 5);
        ll tmp2 = legendere(b, 2);
        ll tmp3 = legendere(b, 5);
        ll tmp4 = ((tmp2 % MOD) - (tmp % MOD)) % MOD;
        ll tmp5 = ((tmp3 % MOD) - (tmp1 % MOD)) % MOD;
        cout << min(tmp4, tmp5) << '\n';
    }
}