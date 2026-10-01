#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define pii pair<int, int>
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
int st1, st2, en1, en2;
int r, c;
int dp[205][205];
bool visited[205][205];

void bfs(int p, int q)
{
    queue<pii> qu;
    qu.push({p, q});
    visited[p][q] = true;
    dp[p][q] = 0;
    while (!qu.empty())
    {
        int i = qu.front().fi;
        int j = qu.front().se;
        qu.pop();
        for (int k = 1; k <= n; ++k)
        {
            if (j + k <= n)
            {
                if (!visited[i][j + k])
                {
                    dp[i][j + k] = min(dp[i][j + k], dp[i][j] + 1);
                    qu.push({i, j + k});
                }
                else
                {
                    break;
                }
            }
        }
        for (int k = 1; k <= n; ++k)
        {
            if (i + k <= n)
            {
                if (!visited[i + k][j])
                {
                    dp[i + k][j] = min(dp[i + k][j], dp[i][j] + 1);
                    qu.push({i + k, j});
                }
            }
        }
        for (int k = 1; k <= n; ++k)
        {
            if (i - k >= 1)
            {
                if (!visited[i - k][j])
                {
                    dp[i - k][j] = min(dp[i - k][j], dp[i][j] + 1);
                    qu.push({i - k, j});
                }
                else
                {
                    break;
                }
            }
        }
        for (int k = 1; k <= n; ++k)
        {
            if (j - k >= 1)
            {
                if (!visited[i][j - k])
                {
                    dp[i][j - k] = min(dp[i][j - k], dp[i][j] + 1);
                    qu.push({i, j - k});
                }
                else
                {
                    break;
                }
            }
        }
    }
}
int main()
{
    FAST();
    cin >> n >> m >> st1 >> st2 >> en1 >> en2;
    while (m--)
    {
        cin >> r >> c;
        visited[r][c] = true;
    }
    for(int i = 1 ; i <= 205 ; ++i)
    {
        for(int j = 1 ; j <= 205 ; ++j)
        {
            dp[i][j] = oo;
        }
    }
    bfs(st1, st2);
    if (dp[en1][en2] == 0)
        cout << "-1";
    else
        cout << dp[en1][en2];
}