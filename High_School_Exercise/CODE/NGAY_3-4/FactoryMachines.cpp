#include <bits/stdc++.h>
using namespace std;
#define ll long long
const long long MOD = 1000000007;
#define MAXN 2 * 100005
const ll oo = 1e18;
void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int n, k;
ll ma = -1;
ll a[MAXN];
ll ans = 0;

void chat()
{
    ll l = 1, r = oo;
    while (l <= r)
    {
        unsigned ll sum = 0;
        unsigned ll mid = (l + r) / 2;
        for (int i = 1; i <= n; ++i)
        {
            sum += mid / a[i];
        }
        if (sum >= k)
        {
            r = mid - 1;
            ans = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
}
int main()
{
    FAST();
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    chat();
    cout << ans;
}
