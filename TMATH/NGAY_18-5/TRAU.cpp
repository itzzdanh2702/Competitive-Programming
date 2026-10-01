#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define pii pair<ll, ll>
const long long MOD = 1000000007;
#define MAXN 2 * 100005
#define oo 1000000000
void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int n;
int a[MAXN];
int mi = oo;
int ma = -1;
int dp[MAXN][4];

int bs(int l, int r, int current_pos, int val)
{
    int pos = 0;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (dp[current_pos][val] - dp[mid][val] == 0)
        {
            r = mid - 1;
            pos = mid;
        }
        else if (dp[current_pos][val] - dp[mid][val] > 0)
        {
            l = mid + 1;
        }
    }
    return pos;
}
void sub12()
{
    ll dem = 0;
    for (int i = 1; i <= n - 1; ++i)
    {
        mi = a[i], ma = a[i];
        for (int j = i + 1; j <= n; ++j)
        {
            mi = min(mi, a[j]);
            ma = max(ma, a[j]);
            if (((a[i] == mi) && (a[j] == ma)) or ((a[i] == ma) && (a[j] == mi)))
            {
                ++dem;
            }
        }
    }
    cout << dem;
}
void sub3()
{
    ll ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= 3; ++j)
        {
            if (a[i] == j)
            {
                dp[i][j] = dp[i - 1][j] + 1;
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] == 3)
        {
            ans += dp[i][1];
            int pos1 = bs(1,i,i,1);
            ans += dp[i][2] - dp[pos1][2];
            int pos2 = bs(1,i,i,2);
            ans += dp[i][3] - dp[max(pos1,pos2)][3];
        }
        else if (a[i] == 2)
        {
            ans += dp[i][3];
            int pos1 = bs(1,i,i,3);
            ans += dp[i][1] - dp[pos1][1];
            int pos2 = bs(1,i,i,1); 
            ans += dp[i][2] - dp[max(pos1,pos2)][2];
        }
        else 
        {
            ans += dp[i][3];
            int pos1 = bs(1,i,i,3);
            ans += dp[i][2] - dp[pos1][2];
            int pos2 = bs(1,i,i,2); 
            ans += dp[i][1] - dp[max(pos1,pos2)][1];  

        }
    }
}
int main()
{
    FAST();
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    sub12();
}