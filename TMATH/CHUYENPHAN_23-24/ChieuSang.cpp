#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define pii pair<ll, ll>
const long long MOD = 1000000007;
#define MAXN 1000005
const ll oo = 1e15;
void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int n, m;
ll a[MAXN], b[MAXN];

void sub2()
{
    ll ans = -oo;
    for (int i = 1; i <= n; ++i)
    {
        int it = lower_bound(b + 1, b + m + 1, a[i]) - b;
        int it1 = it - 1;
        if (it == m + 1)
            ans = max(ans, abs(b[it1] - a[i]));
        else if (it == 1)
            ans = max(ans, abs(b[it] - a[i]));
        else
        {
            if (abs(b[it] - a[i]) < abs(b[it1] - a[i]))
                ans = max(ans, abs(b[it] - a[i]));
            else
                ans = max(ans, abs(b[it1] - a[i]));
        }
    }
    cout << ans;
}
int main()
{
    FAST();
    freopen("CHIEUSANG.INP","r",stdin);
    freopen("CHIEUSANG.INP","w",stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= m; ++i)
        cin >> b[i];
    sort(b + 1, b + m + 1);
    sub2();
}