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

string S, max_str[MAXN], ans = " ";
int dp[MAXN], sz = 0;

int main()
{
    FAST();
    cin >> S;
    for (int i = 0; i < S.size(); ++i)
        dp[i] = 1;
    for (int i = 0; i < S.size(); ++i)
    {
        max_str[i] = S[i];
        for (int j = 0; j <= i - 1; ++j)
        {
            if (S[i] < S[j])
            {
                if (dp[j] + 1 > dp[i])
                {
                    dp[i] = dp[j] + 1;
                    max_str[i] = max_str[j] + S[i];
                }
                else if (dp[j] + 1 == dp[i])
                {
                    if (max_str[j] + S[i] > max_str[i])
                        max_str[i] = max_str[j] + S[i];
                }
            }
        }
    }
    // cout << max_str[S.size() - 1];
    for (int i = 0; i < S.size(); ++i)
    {
        if (max_str[i].size() > sz)
        {
            ans = max_str[i];
            sz = max_str[i].size();
        }
        else if (max_str[i].size() == sz)
        {
            if (max_str[i] > ans)
                ans = max_str[i];
        }
    }
    cout << ans;
}