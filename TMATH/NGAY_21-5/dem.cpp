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
bool check[MAXN];
int trace[10001][10001];
pair<int, int> p[MAXN];
vector<string> v;
string tmp;
string ans;
int cnt = 0;
ll ma = -1;
bool cmp(pii a, pii b)
{
    if (a.se != b.se)
    {
        return a.fi < b.fi;
    }
    else
    {
        return a.se > b.se;
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
        for(auto x : v1[tmp])
        {
            if (trace[x][tmp] != 0)
            {
                if (x < 0)
                {
                    continue;
                }
                if (S[x].size() != 0)
                {
                    string tmp2 = to_string(trace[x][tmp]);
                    tmp2 += S[tmp];
                    if ((tmp2.size() > S[x].size()))
                    {
                        S[x] = "";
                        S[x] += to_string(trace[x][tmp]);
                        S[x] += S[tmp];
                    }
                    else if (tmp2.size() == S[x].size())
                    {
                        if (tmp2 > S[x])
                        {
                            S[x] = "";
                            S[x] += to_string(trace[x][tmp]);
                            S[x] += S[tmp];
                        }
                    }
                }
                else
                {
                    S[x] += to_string(trace[x][tmp]);
                    S[x] += S[tmp];
                }
                if (x == 0)
                {
                    sort(S[0].begin(), S[0].end());
                    reverse(S[0].begin(), S[0].end());
                    v.push_back(S[0]);
                }
                // cout << tmp - p[i].fi << '\n';
                qu.push(x);
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
        // 5 3 7
        sort(p + 1, p + m + 1, cmp);
        for (int i = 1; i <= m; ++i)
        {
            dp[p[i].fi] = 0;
        }
        dp[0] = 0;
        for (int i = 1; i <= m; ++i)
        {
            trace[0][p[i].fi] = p[i].se;
        }
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
            {
                if (i > p[j].fi)
                {
                    if (dp[i - p[j].fi] + 1 > dp[i])
                    {
                        dp[i] = max(dp[i], dp[i - p[j].fi] + 1);
                    }
                }
            }
            for (int j = 1; j <= m; ++j)
            {
                if (dp[i] - 1 == dp[i - p[j].fi])
                {
                    trace[i - p[j].fi][i] = p[j].se;
                }
            }
        }
        bfs(n);
        for (auto x : v)
        {
            ll tmp = x.size();
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
        //  cout << trace[11][15];
        // cout << S[0];
        // int tmp1 = dp[n];
        // int tmp2 = n;

        // // cout << tmp1;
        // while (n > 0)
        // {
        //     ++dem;
        //     if (dem == tmp1)
        //     {
        //         int tmp5 = -1;
        //         int c = 0;
        //         cout << n << ' ';
        //         for (int i = 1; i <= m; ++i)
        //         {
        //             if (p[i].fi == n)
        //             {
        //                 if (p[i].se > tmp5)
        //                 {
        //                     tmp5 = p[i].se;
        //                     c = p[i].se;
        //                 }
        //             }
        //         }
        //         if (c == 0)
        //         {
        //             n += b[int(tmp[tmp.size() - 1] - 48)];
        //             check[int(tmp[tmp.size() - 1] - 48)][dem - 1] = 1; // se
        //             if (tmp.size() > 0)
        //                 tmp.pop_back();
        //             dem -= 2;
        //             cout << tmp << ' ' << n << ' ' << dem;
        //             return 0;
        //         }
        //         else
        //         {
        //             tmp += to_string(c);
        //             break;
        //         }
        //     }
        //     int tmp4 = -1;
        //     int tmp3;
        //     int tmp2 = 0;
        //     for (int i = 1; i <= m; ++i)
        //     {
        //         if (!check[p[i].se][dem])
        //         {
        //             if (dp[n - p[i].fi] + 1 == dp[n])
        //             {
        //                 if (n > p[i].fi)
        //                 {
        //                     if (p[i].se > tmp4)
        //                     {
        //                         tmp2 = max(tmp4, p[i].se);
        //                         tmp3 = p[i].fi;
        //                         tmp4 = p[i].se;
        //                     }
        //                 }
        //             }
        //         }
        //     }
        //     if (tmp2 == 0)
        //     {
        //         n += b[int(tmp[tmp.size() - 1] - 48)];
        //         check[int(tmp[tmp.size() - 1] - 48)][dem - 1] = 1;
        //         if (tmp.size() > 0)
        //             tmp.pop_back();
        //         dem -= 2;
        //     }
        //     else
        //     {
        //         tmp += to_string(tmp2);
        //         n -= tmp3;
        //     }
        // }
        // sort(tmp.begin(), tmp.end());
        // reverse(tmp.begin(), tmp.end());
        // cout << tmp;
    }