#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nmax 10
#define pii pair<ll, ll>
#define fi first
#define se second
ll a, b, c, a0, b0, c0, n;
ll a1[105], b1[105], c1[105], a2[105], b2[105], c2[105], visited[105][105][105], dp[105][105][105];

bool bfs(ll a, ll b, ll c)
{
    queue<pair<ll, pii>> qu;
    visited[a][b][c] = true;
    if ((a == a0) and (b == b0) and (c == c0))
    {
        cout << "0";
        exit(0);
    }
    qu.push({a, {b, c}});
    while (!qu.empty())
    {
        tuple<ll, ll, ll> t;
        t = make_tuple(qu.front().fi, qu.front().se.fi, qu.front().se.se);
        qu.pop();
        for (int i = 1; i <= n; i++)
        {
            if ((get<0>(t) >= a1[i]) and (get<1>(t) >= b1[i]) and (get<2>(t) >= c1[i]))
            {
                ll val0 = get<0>(t) - a1[i] + a2[i];
                ll val1 = get<1>(t) - b1[i] + b2[i];
                ll val2 = get<2>(t) - c1[i] + c2[i];
                if ((val0 == a0) and (val1 == b0) and (val2 == c0))
                {
                    dp[val0][val1][val2] = dp[get<0>(t)][get<1>(t)][get<2>(t)] + 1;
                    return true;
                }
                if ((val0 <= 10) and (val1 <= 10) and (val2 <= 10) and (!visited[val0][val1][val2]))
                {
                    qu.push({val0, {val1, val2}});
                    visited[val0][val1][val2] = true;
                    dp[val0][val1][val2] = dp[get<0>(t)][get<1>(t)][get<2>(t)] + 1;
                }
            }
        }
    }
    return false;
}
int main()
{
    cin >> a >> b >> c >> a0 >> b0 >> c0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a1[i] >> b1[i] >> c1[i] >> a2[i] >> b2[i] >> c2[i];
    }
    memset(dp, 0, sizeof(dp));
    memset(visited, false, sizeof(visited));
    if (bfs(a, b, c))
    {
        cout << dp[a0][b0][c0] << ' ';
    }
    else
        cout << "-1" << ' ';
}