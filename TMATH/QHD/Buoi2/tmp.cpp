#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define pii pair<ll, ll>
const long long MOD = 1000000007;
#define MAXN 1005
#define oo 1000000000
void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int n;
int a[MAXN];
int pos[MAXN];
int dp[MAXN];
string tmp[100005];
string S;

int main(int argc, char const *argv[])
{
    FAST();
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        tmp[i] = to_string(a[i]);
    }
    for (int i = 1; i <= n; ++i)
        dp[i] = 1;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = i + 1; j <= n; ++j)
        {
            if (a[j] > a[i])
            {
                if (dp[i] + 1 > dp[j])
                {
                    dp[j] = dp[i] + 1;
                    tmp[j] = tmp[i] + '|' + to_string(a[j]);
                }
            }
        }
    }
    string ans;
    int ma = -oo;
    for (int i = 1; i <= n; ++i)
    {
        if (dp[i] > ma)
        {
            ma = dp[i];
            ans = tmp[i];
        }
    }
    // sort(ans.begin(), ans.end());
    int cnt = 0;
    cout << ma << '\n';
    //cout << ans << '\n';
    for (auto x : ans)
    {
        if (x != '|')
            cout << x;
        else 
            cout << ' ';
    }
    // cout << cnt;
}