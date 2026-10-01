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
int n, k;
ll a[MAXN];
ll sum[MAXN];
int main()
{
    FAST();
    cin >> TC;
    while (TC--)
    {
        ll tmp = 0;
        ll dem = 0;
        cin >> n >> k;
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i];
            sum[i] = i + a[i];
        }
        sort(sum + 1, sum + n + 1);
        for (int i = 1; i <= n; ++i)
        {
            tmp += sum[i];
            if (tmp <= k)
            {
                ++dem;
            }
        }
        cout << dem << '\n';
    }
}