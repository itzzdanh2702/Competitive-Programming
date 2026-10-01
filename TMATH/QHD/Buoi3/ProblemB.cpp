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

ll n;
ll a[MAXN];
ll ma_pre[MAXN], mi_suffix[MAXN];
ll ans;

int main()
{
    FAST();
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        ma_pre[i] = -oo;
        mi_suffix[i] = oo;
    }
    for (int i = 1; i <= n; ++i)
    {
        ma_pre[i] = max(ma_pre[i - 1], a[i - 1]);
    }
    for (int i = n; i >= 1; --i)
    {
        mi_suffix[i] = min(mi_suffix[i + 1], a[i + 1]);
    }
    for (int i = 1; i <= n; ++i)
    {
        ans = max(ans, ma_pre[i] + a[i] - mi_suffix[i]);
    }
    cout << ans; 
}