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

int n, m;
int a[MAXN];
int dp[MAXN];
int dem = 0;
int b[MAXN];
bool check[10005];
vector<string> v;
pair<int, int> p[MAXN];
string S;
string tmp;
string ans;

bool cmp(pii a, pii b)
{
    if (a.fi != b.fi)
    {
        return a.fi < b.fi;
    }
    else
    {
        return a.se > b.se;
    }
}
void dfs(int u, int val)
{
    if (S.size() == dp[val])
    {
        v.push_back(S);
        // cout << S << '\n';
        S = "";
    }
    if (u > val)
    {
        S = "";
        return;
    }
    if (u == val)
    {
        S = "";
        return;
    }

    for (int i = 1; i <= m; ++i)
    {
        if (dp[u + p[i].fi] == dp[u] + 1)
        {
            S += to_string(p[i].se);
            dfs(u + p[i].fi, val);
        }
    }
}
int main()
{
    FAST();
    cin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        cin >> a[i];
        if (a[i] == 1)
            p[i].fi = 2, p[i].se = 1;
        else if (a[i] == 2)
            p[i].fi = 5, p[i].se = 2;
        else if (a[i] == 3)
            p[i].fi = 5, p[i].se = 3;
        else if (a[i] == 4)
            p[i].fi = 4, p[i].se = 4;
        else if (a[i] == 5)
            p[i].fi = 5, p[i].se = 5;
        else if (a[i] == 6)
            p[i].fi = 6, p[i].se = 6;
        else if (a[i] == 7)
            p[i].fi = 3, p[i].se = 7;
        else if (a[i] == 8)
            p[i].fi = 7, p[i].se = 8;
        else if (a[i] == 9)
            p[i].fi = 6, p[i].se = 9;
        b[p[i].se] = p[i].fi;
    }
    sort(p + 1, p + m + 1, cmp);
    for (int i = 1; i <= m; ++i)
    {
        dp[p[i].fi] = 1;
    }
    dp[0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (i > p[j].fi)
            {
                dp[i] = max(dp[i], dp[i - p[j].fi] + 1);
            }
        }
    }
    for (int i = n + 1; i <= MAXN; ++i)
    {
        dp[i] = oo;
    }
    dfs(0, n);
    for (int i = 0; i < v.size(); ++i)
    {
        int sum = 0;
        for (int j = 0; j < v[i].size(); ++j)
        {
            sum += b[int(v[i][j] - 48)];
        }
        cout << sum << '\n';
        if (sum == n)
        {
            sort(v[i].begin(), v[i].end());
            reverse(v[i].begin(), v[i].end());
            ans = max(ans, v[i]);
        }
    }
    cout << ans;
}