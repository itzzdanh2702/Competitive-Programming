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
int n;
int a[MAXN];
int b[MAXN];

ll get(ll a, ll b)
{
    return ((a % MOD) * (b % MOD)) % MOD;
}
int main()
{
    FAST();
    cin >> TC;
    while (TC--)
    {
        bool check = 0;
        ll ans = 1;
        cin >> n;
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i];
        }
        sort(a + 1, a + n + 1);
        for (int i = 1; i <= n; ++i)
        {
            cin >> b[i];
        }
        sort(b + 1, b + n + 1);
        for (ll i = n; i >= 1; --i)
        {
            int it = upper_bound(a + 1, a + n + 1, b[i]) - a;
            if (it == n + 1)
            {
                cout << "0" << '\n';
                check = 1;
                break;
            }
            ans *= (i - it + 1);
            ans %= MOD;
        }
        if (check)
            continue;
        cout << ans << '\n';
    }
}