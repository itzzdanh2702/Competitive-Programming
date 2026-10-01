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

ll mu(ll a, ll b, ll m) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = (__int128)res * a % m;
        a = (__int128)a * a % m;
        b >>= 1;
    }
    return res;
}
int main()
{
    FAST();
    cin >> TC;
    while (TC--)
    {
        ll a, b, n;
        cin >> a >> b >> n;
        ll tmp = abs(a - b);
        if (tmp == 0)
        {
            cout << (mu(a, n, MOD) + mu(b, n, MOD)) % MOD << '\n';
        }
        else if (tmp == 1)
        {
            cout << 1 << '\n';
        }
        else
        {
            ll tmp1 = (mu(a, n, tmp) + mu(b, n, tmp))%tmp;
            cout << __gcd(tmp,tmp1) % MOD << '\n';
        }
    }
}