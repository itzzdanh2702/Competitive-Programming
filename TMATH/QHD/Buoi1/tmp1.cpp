#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define pii pair<ll, ll>
const long long MOD = 1000000007;
const int MAXN = 5e5 + 5;
#define oo 1000000000
void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int n;
int a[MAXN];
int TC;
ll pre[MAXN];
ll suffix[MAXN];
ll ma_pre[MAXN];
ll ma_suffix[MAXN];
ll mi_pre[MAXN];
ll mi_suffix[MAXN];
int main()
{
    FAST();
    cin >> TC;
    while (TC--)
    {
        ll mi = oo, mi1 = oo;
        ll ans = -oo;
        cin >> n;
        for (int i = 1; i <= n; ++i)
        {
            ma_pre[i] = -oo;
            ma_suffix[i] = -oo;
            mi_pre[i] = oo;
            mi_suffix[i] = oo;
        }
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i];
            pre[i] = pre[i - 1] + a[i];
        }
        mi = 0;
        for (int i = 1; i <= n; ++i)
        {
            ma_pre[i] = max(ma_pre[i - 1], pre[i] - mi);
            mi = min(mi, pre[i]);
        }
        suffix[n + 1] = 0;
        for (int i = n; i >= 1; --i)
        {
            suffix[i] = suffix[i + 1] + a[i];
        }
        mi1 = 0;
        ma_suffix[n + 1] = 0;
        for (int i = n; i >= 1; --i)
        {
            ma_suffix[i] = max(ma_suffix[i + 1], suffix[i] - mi1);
            mi1 = min(mi1, suffix[i]);
        }
        for (int i = 1; i <= n; ++i)
        {
            // cout << ma_pre[i] << ' ';
            ans = max(ans, ma_pre[i - 1] + ma_suffix[i + 1]);
        }
        cout << ans << '\n';
    }
}