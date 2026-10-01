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
ll TC;
ll pre[MAXN] , pre1[MAXN];
ll a[MAXN];
ll dp[MAXN];

int main()
{
    FAST();
    cin >> TC;
    while (TC--)
    {
        memset(dp, 0, sizeof(dp));
        memset(pre, 0, sizeof(pre));
        memset(pre1, 0, sizeof(pre));
        cin >> n;
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i];
            pre[i] = pre[i - 1] + a[i];
        }
        for (int i = 1; i <= n; ++i)
        {
            ll pos1 = i;
            ll pos2 = ;
            ll l1 = 1, r1 = i;
            while (l1 <= r1)
            {
                ll mid1 = (l1 + r1) / 2;
                if (a[i] >= pre[i - 1] - pre[mid1 - 1])
                {
                    r1 = mid1 - 1;
                    pos1 = mid1 + 1;
                }
                else
                {
                    l1 = mid1 + 1;
                }
            }
            ll l2 = i + 1, r2 = n;
            while (l2 <= r2)
            {
                ll mid2 = (l2 + r2) / 2;
                if (a[i] >= pre[mid2] - pre[i])
                {
                    l2 = mid2 + 1;
                    pos2 = mid2 + 1;
                }
                else
                {
                    r2 = mid2 - 1;
                }
            }
            dp[pos1]++;   
            dp[pos2 + 1]--;
        }
        for(int i = 1 ; i <= n ; ++i)
        {
            pre1[i] = pre1[i - 1] + dp[i]; 
        }
        for(int i = 1 ; i <= n ; ++i)
        {
            cout << pre1[i] << ' ';
        }
    cout << '\n';
    }
}