/// Code by tom270207 from a2k51.cpp
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define pii pair<ll, ll>
#define MAXN 10005
#define oo 1000000000
void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int n, m;
int dem = 0;
int mi1 = oo;
int a[10];
int dp[MAXN];
int b[MAXN];
bool check[10][5000];
pair<int, int> p[MAXN];
string tmp,ans;

void prepare()
{
    for (int i = 1; i <= m; ++i)
        dp[p[i].fi] = 1;
    dp[0] = 0;
    for (int i = mi1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (i > p[j].fi)
            {
                if (i - p[j].fi == 0)
                {
                    dp[i] = max(dp[i], dp[0] + 1);
                    continue;
                }
                if (dp[i - p[j].fi] != 0)
                    if (dp[i - p[j].fi] + 1 > dp[i])
                        dp[i] = dp[i - p[j].fi] + 1;
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
        mi1 = min(mi1, p[i].fi);
    }
    prepare();
    int tmp1 = dp[n], tmp5 = -1;
    while (n > 0)
    {
        ++dem;
        if (dem == tmp1)
        {
            int c = 0;
            for (int i = 1; i <= m; ++i)
            {
                if (p[i].fi == n)
                {
                    if (p[i].se > tmp5)
                    {
                        tmp5 = p[i].se;
                        c = p[i].se;
                    }
                }
            }
            if (c == 0)
            {
                n += b[int(tmp[tmp.size() - 1] - 48)];
                check[int(tmp[tmp.size() - 1] - 48)][dem - 1] = 1;
                tmp.pop_back();
                dem -= 2;
                continue;
            }
            else
            {
                tmp += to_string(c);
                break;
            }
        }
        int tmp4 = -1, tmp3;
        for (int i = 1; i <= m; ++i)
            if (!check[p[i].se][dem])
                if (dp[n - p[i].fi] + 1 == dp[n])
                    if (n > p[i].fi)
                        if (p[i].se > tmp4)
                        {
                            tmp3 = p[i].fi;
                            tmp4 = p[i].se;
                        }
        if (tmp4 == 0)
        {
            n += b[int(tmp[tmp.size() - 1] - 48)];
            check[int(tmp[tmp.size() - 1] - 48)][dem - 1] = 1;
            tmp.pop_back();
            dem -= 2;
        }
        else
        {
            tmp += to_string(tmp4);
            n -= tmp3;
        }
    }
    cout << tmp;
}