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
int n;
int a[MAXN];
int ans[MAXN];
int prefix_sum[MAXN];

int main()
{
    FAST();
    cin >> TC;
    while (TC--)
    {
        int cnt_left = 0, cnt_right = 0;
        cin >> n;
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i];
        }
        int l = 1, r = n;
        while (l <= r)
        {
            if (cnt_left >= cnt_right)
            {
                if (a[r] == 1)
                {
                    ans[r] = 1;
                    ++cnt_right;
                }
                else
                {
                    ans[r] = 0;
                }
                --r;
            }
            else
            {
                if (a[l] == 0)
                {
                    ans[l] = 1;
                    ++cnt_left;
                }
                else
                {
                    ans[l] = 0;
                }
                ++l;
            }
        }
        for (int i = 1; i <= n; ++i)
        {
            if (ans[i] == 0)
            {
                prefix_sum[i] = prefix_sum[i - 1];
            }
            else
            {
                prefix_sum[i] = prefix_sum[i - 1] + ans[i];
            }
        }
        bool check = 0;
        for (int i = 1; i <= n; ++i)
        {
            if (ans[i] == 1)
            {
                if ((a[i] == 1) && (prefix_sum[i - 1] < prefix_sum[n] - prefix_sum[i]))
                {
                    cout << "-1" << '\n';
                    check = 1;
                    break;
                }
                if ((a[i] == 0) && (prefix_sum[i - 1] >= prefix_sum[n] - prefix_sum[i]))
                {
                    cout << "-1" << '\n';
                    check = 1;
                    break;
                }
            }
            else
            {
                if ((a[i] == 0) && (prefix_sum[i - 1] < prefix_sum[n] - prefix_sum[i]))
                {
                    cout << "-1" << '\n';
                    check = 1;
                    break;
                }
                if ((a[i] == 1) && (prefix_sum[i - 1] >= prefix_sum[n] - prefix_sum[i]))
                {
                    cout << "-1" << '\n';
                    check = 1;
                    break;
                }
            }
        }
        if (check)
        {
            continue;
        }
        for (int i = 1; i <= n; ++i)
        {
            cout << ans[i] << ' ';
        }
        cout << '\n';
    }
}