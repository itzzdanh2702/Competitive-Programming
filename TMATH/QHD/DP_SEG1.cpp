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

ll n;
ll a[MAXN];
ll max_val1[MAXN], max_val2[MAXN];
ll ans = -1;

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
        max_val1[i] = max(max_val1[i - 1], a[i]);
    }
    for (int i = n; i >= 1; --i)
    {
        max_val2[i] = max(max_val2[i + 1], a[i]);
    }
    for (int i = 1; i <= n; ++i)
    {
        ans = max(ans, max_val1[i] - a[i] + max_val2[i]);
    }
    cout << ans;
}
// tong[r] - tong[l - 1] <= k