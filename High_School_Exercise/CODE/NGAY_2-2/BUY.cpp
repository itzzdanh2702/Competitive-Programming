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

ll n, m, k;
ll a[MAXN];
ll pre1[MAXN], pre2[MAXN];
ll ans1 = -1, ans2 = -1;

int main()
{
    //freopen("BUY.inp", "r", stdin);
    //freopen("BUY.out", "w", stdout);
    FAST();
    cin >> n >> m >> k;
    pre1[0] = pre2[0] = 0;
    for (int i = 1; i <= n; ++i)
    {  
         cin >> a[i];    
    }
    sort(a + 1, a + n + 1, greater<ll>());
    for (int i = 1; i <= n; ++i)
    {
        pre1[i] = pre1[i - 1] + a[i];
        pre2[i] = pre2[i - 1] + a[i] - a[i] / 2;
    }
    for (int i = 1; i <= n; ++i)
    {
        ll sum = 0, pos = 0;
        ll l = 1, r = n;
        while (l <= r)
        {
            ll mid = (l + r) / 2;
            if (mid - i + 1 <= m)
            {
                if (pre2[mid] - pre2[i - 1] > k)
                {
                    r = mid - 1;
                }
                else if (pre2[mid] - pre2[i - 1] == k)
                {
                    pos = mid - i + 1;
                    sum = pre2[mid] - pre2[i - 1];
                    break;
                }
                else if (pre2[mid] - pre2[i - 1] < k)
                {
                    l = mid + 1;
                    pos = mid - i + 1;
                    sum = pre2[mid] - pre2[i - 1];
                }
            }
            else
            {
                if (pre2[i + m - 1] - pre2[i - 1] + pre1[mid] - pre1[i + m - 1] > k)
                {
                    r = mid - 1;
                }
                else if (pre2[i + m - 1] - pre2[i - 1] + pre1[mid] - pre1[i + m - 1] == k)
                {
                    pos = mid - i + 1;
                    sum = pre2[i + m - 1] - pre2[i - 1] + pre1[mid] - pre1[i + m - 1];
                    break;
                }
                else
                {
                    l = mid + 1;
                    pos = mid - i + 1;
                    sum = pre2[i + m - 1] - pre2[i - 1] + pre1[mid] - pre1[i + m - 1];
                }
            }
        }
        if (pos > ans1)
        {
            ans1 = pos;
            ans2 = sum;
        }
        else if (pos == ans1)
        {
            ans1 = pos;
            ans2 = min(ans2, sum);
        }
    }
    cout << ans1 << ' ' << ans2;
}
