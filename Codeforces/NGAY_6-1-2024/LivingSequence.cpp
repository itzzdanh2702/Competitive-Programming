#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1000005

void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int TC;
int64_t ans1;
vector<int> digit;
int64_t dp[13], d[13];
int64_t pos;

ll POW(int x, int y)
{
    ll ans = 1;
    for (int i = 1; i <= y; ++i)
        ans *= x;
    return ans;
}

void build()
{
    dp[1] = 1;
    d[1] = 1;
    for (int i = 2; i <= 12; ++i)
        dp[i] = 9 * dp[i - 1] + POW(10, i - 1);
}

int64_t solve(ll p)
{
    digit.clear();
    int64_t ans = 0;
    while (p > 0)
    {
        digit.push_back(p % 10);
        p /= 10;
    }
    reverse(digit.begin(), digit.end());
    int n = digit.size();
    int cnt = n - 1;
    for (int i = 0; i < digit.size(); ++i)
    {
        if (digit[i] > 0)
            ans += dp[cnt];
        if (digit[i] > 4)
            ans += POW(10, cnt) + (digit[i] - 2) * dp[cnt];
        else
        {
            if (digit[i] == 4)
            {
                int64_t tmp = 0;
                for (int j = i + 1; j < digit.size(); ++j)
                {
                    if (j == i + 1)
                        tmp = digit[j];
                    else
                    {
                        tmp *= 10;
                        tmp += digit[j];
                    }
                }
                ans += tmp;
                ans += (digit[i] - 1) * dp[cnt];
                break;
            }
            if (digit[i] > 1)
                ans += (digit[i] - 1) * dp[cnt];
        }
        --cnt;
    }
    return ans;
}

bool check(int64_t k)
{
    if (k - solve(k) <= pos)
        return true;
    return false;
}

int main(int argc, char const *argv[])
{
    FAST();
    build();
    cin >> TC;
    while (TC--)
    {
        cin >> pos;
        int64_t l = 0, r = 1e18;
        while (l <= r)
        {
            int64_t mid = (l + r) / 2;
            if (check(mid))
            {
                l = mid + 1;
                ans1 = mid;
            }
            else
                r = mid - 1;
        }
        cout << ans1 << '\n';
    }
    return 0;
}