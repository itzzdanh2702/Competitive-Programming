#include <bits/stdc++.h>
using namespace std;
#define ll long long
const long long MOD = 1000000007;
#define MAXN 1005
#define oo 1000000000
void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int n, x;
int w[MAXN], p[MAXN];

int main()
{
    FAST();
    cin >> n >> x;
    vector<int> price(n), pages(n);
    for (int &v : price)
        cin >> v;
    for (int &v : pages)
        cin >> v;
    vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j <= x; ++j)
        {
            dp[i][j] = dp[i - 1][j];
            if (j >= price[i])
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - price[i]] + pages[i]);
            }
        }
    }
    cout << dp[n][x];
}