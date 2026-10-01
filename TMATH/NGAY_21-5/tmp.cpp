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
bool check[MAXN];
int trace[10001][10001];
pair<int, int> p[MAXN];
vector<string> v;
vector<int> v1[MAXN];
string tmp;
string ans;
int cnt = 0;
int ma = -1;
int ma1 = -1, mi1 = oo;
bool cmp(pii a, pii b)
{
    if (a.fi != b.fi)
    {
        return a.fi > b.fi;
    }
    else
    {
        return a.se < b.se;
    }
}
string S[MAXN];
void bfs(int k)
{
    queue<int> qu;
    qu.push(k);
    while (!qu.empty())
    {
        int tmp = qu.front();
        qu.pop();
        for (auto x : v1[tmp])
        {
            if (!check[x])
            {
                if (trace[x][tmp] != 0)
                {
                    S[x] += to_string(trace[x][tmp]);
                    S[x] += S[tmp];
                    if (x == 0)
                    {
                        sort(S[0].begin(), S[0].end());
                        reverse(S[0].begin(), S[0].end());
                        v.push_back(S[0]);
                    }
                    if (x != 0)
                        check[x] = true;
                    else
                        S[0] = "";
                    // cout << x << '\n';
                    qu.push(x);
                }
            }
        }
    }
}
// 6111111111111111111111111111111111111111111
// 111111111111111111111111111111111111111111111
int main()
{
    // 7 3 5
    FAST();
    cin >> n >> m;
    memset(check, 0, sizeof(check));
    for (int i = 1; i <= m; ++i)
    {
        cin >> a[i];
        if (a[i] == 1)
            p[i].se = 2, p[i].fi = 1;
        else if (a[i] == 2)
            p[i].se = 5, p[i].fi = 2;
        else if (a[i] == 3)
            p[i].se = 5, p[i].fi = 3;
        else if (a[i] == 4)
            p[i].se = 4, p[i].fi = 4;
        else if (a[i] == 5)
            p[i].se = 5, p[i].fi = 5;
        else if (a[i] == 6)
            p[i].se = 6, p[i].fi = 6;
        else if (a[i] == 7)
            p[i].se = 3, p[i].fi = 7;
        else if (a[i] == 8)
            p[i].se = 7, p[i].fi = 8;
        else if (a[i] == 9)
            p[i].se = 6, p[i].fi = 9;
        mi1 = min(p[i].se, mi1);
        ma1 = max(p[i].se, ma1);
        // b[p[i].se] = p[i].fi;
    }
    // 5 3 7
    sort(p + 1, p + m + 1, cmp);
    for (int i = 1; i <= m; ++i)
    {
        dp[p[i].se] = 1;
    }
    dp[0] = 0;
    for (int i = 1; i <= m; ++i)
    {
        trace[0][p[i].se] = p[i].fi;
    }
    for (int i = mi1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (i > p[j].se)
            {
                if (i - p[j].se == 0)
                {
                    dp[i] = max(dp[i], dp[0] + 1);
                    continue;
                }
                if (dp[i - p[j].se] != 0)
                {
                    if (dp[i - p[j].se] + 1 > dp[i])
                    {
                        dp[i] = dp[i - p[j].se] + 1;
                    }
                }
            }
        }
        for (int j = 1; j <= m; ++j)
        {
            if (dp[i] - 1 == dp[i - p[j].se])
            {
                trace[i - p[j].se][i] = p[j].fi;
            }
        }
    }
    for (int i = n; i >= 1; --i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (i - p[j].se < 0)
            {
                continue;
            }
            if (trace[i - p[j].se][i] != 0)
            {
                v1[i].push_back(i - p[j].se);
            }
        }
    }
    //cout << dp[n] << '\n';
    bfs(n);
    for (auto x : v)
    {
        int tmp = x.size();
        ma = max(ma, tmp);
    }
    for (auto x : v)
    {
        if (x.size() == ma)
        {
            ans = max(ans, x);
        }
    }
    cout << ans;
}