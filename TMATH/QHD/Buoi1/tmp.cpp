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
string tmp[MAXN];
string S;

int main(int argc, char const *argv[])
{
    FAST();
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        pos[a[i]] = i;
        tmp[i] = to_string(i);
    }
    for (int i = 1; i <= n; ++i)
        dp[i] = 1;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = i + 1; j <= n; ++j)
        {
            if (pos[j] > pos[i])
            {
                if (dp[i] + 1 > dp[j])
                {
                    dp[j] = dp[i] + 1;
                    tmp[j] = tmp[i] + '|' + to_string(j);
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
    int cnt = 0;
    cout << ma << '\n';
    for (auto x : ans)
    {
        if (x != '|')
            cout << x;
        else 
            cout << ' ';
    }
}
