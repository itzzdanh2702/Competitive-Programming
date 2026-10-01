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

ll n, a[MAXN];
ll ans = 0;
ll pre[MAXN], pre1[MAXN], pre2[MAXN];
ll S = 0;

ll get(ll a, ll b)
{
    return ((a % MOD) * (b % MOD)) % MOD;
}
ll get1(ll x, ll y)
{
    return ((x % MOD) + (y % MOD)) % MOD;
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    for (int i = n; i >= 1; --i)
    {
        pre[i] = pre[i + 1] + a[i];
        pre[i] %= MOD;
        pre1[i] = get1(pre1[i + 1], get(a[i], a[i]));
        pre1[i] %= MOD;
        pre2[i] = get1(pre2[i + 1], get(get(a[i], a[i]), a[i]));
        pre2[i] %= MOD;
    }
    for (int i = 1; i <= n; ++i)
    {
        ans += get1(get1(get1(get(n - i, get(get(a[i], a[i]), a[i])), -pre2[i + 1]), -3LL * get(get(a[i], a[i]), pre[i + 1])), 3LL * get(a[i], pre1[i + 1]));
        ans %= MOD;
    }
    cout << ans % MOD;
}