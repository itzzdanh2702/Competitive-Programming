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
int dp[MAXN];
bool check[MAXN];
void solve()
{
    vector<int> v, v1;
    if (a[n] == 1)
    {
        cout << "NO" << '\n';
        return;
    }
    cout << "YES" << '\n';
    for (int i = 1; i <= n; ++i)
        if (a[i] == 0)
            v.push_back(i - 1);
    int tmp = 0;
    for (int i = 0; i < v.size(); ++i)
    {
        v1.push_back(v[i]);
        check[v[i]] = 1;
        for (int j = tmp; j < v[i]; ++j)
            v1.push_back(j);
        tmp = v[i] + 1;
    }
    int tmp1 = 0;
    int tmp2 = 0;
    for (int i = 0; i < v1.size(); ++i)
        dp[v1[i]] = v1[i];
    for (int i = 0; i < v1.size(); ++i)
        if (check[v1[i]])
        {
            dp[v1[i]] -= tmp1;
            ++tmp1;
        }
        else
        {
            dp[v1[i]] -= tmp1 - 1;
            ++tmp1;
        }
    for (int i = v1.size() - 1; i >= 0; --i)
        cout << dp[v1[i]] << ' ';
    for (int i = 0; i < v1.size(); ++i)
    {
        dp[v1[i]] = 0;
        check[v1[i]] = 0;
    }
    cout << '\n';
}
int main()
{
    FAST();
    cin >> TC;
    while (TC--)
    {
        cin >> n;
        for (int i = 1; i <= n; ++i)
            cin >> a[i];
        solve();
    }
}