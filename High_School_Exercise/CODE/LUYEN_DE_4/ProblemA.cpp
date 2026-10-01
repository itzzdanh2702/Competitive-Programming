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

int n;
ll a[MAXN], b[MAXN], c[MAXN];
ll mi1[MAXN], ma1[MAXN], mi2[MAXN], ma2[MAXN], mi3[MAXN], ma3[MAXN], mi4[MAXN], ma4[MAXN], store[MAXN], store1[MAXN];
ll ans = -oo;

int main()
{
    cin >> n;
    ma1[0] = -oo;
    mi1[0] = oo;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        ma1[i] = max(ma1[i - 1], a[i]);
        mi1[i] = min(mi1[i - 1], a[i]);
    }
    for (int i = 1; i <= n; ++i)
    {
        cin >> b[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        cin >> c[i];
    }
    store[1] = -oo;
    store1[1] = oo;
    mi3[1] = mi4[1] = oo;
    ma3[1] = ma4[1] = -oo;
    for (int i = 2; i <= n; ++i)
    {
        store[i] = max(b[i] * ma1[i - 1], b[i] * mi1[i - 1]);
        store1[i] = min(b[i] * ma1[i - 1], b[i] * mi1[i - 1]);
        mi3[i] = min(mi3[i - 1], store[i]);
        ma3[i] = max(ma3[i - 1], store[i]);
        mi4[i] = min(mi4[i - 1], store1[i]);
        ma4[i] = max(ma4[i - 1], store1[i]);
    }
    for (int i = 3; i <= n; ++i)
    {
        ans = max({ans, c[i] * mi3[i - 1], c[i] * ma3[i - 1], c[i] * mi4[i - 1], c[i] * ma4[i - 1]});
    }
    cout << ans;
}
