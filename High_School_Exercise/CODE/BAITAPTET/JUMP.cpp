#include <bits/stdc++.h>
using namespace std;
#define ll long long
const long long MOD = 1000000007;
#define MAXN 1000005
#define oo 1000000000
void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll n, x, y;
ll dp[MAXN];
bool visited[MAXN];

void bfs(ll st, ll y, ll x)
{
    memset(dp, 0, sizeof(dp));
    memset(visited, 0, sizeof(visited));
    queue<ll> qu;
    qu.push(st);
    visited[st] = true;
    dp[st] = 0;
    while (!qu.empty())
    {
        ll top = qu.front();
        qu.pop();
        if (top == x)
        {
            cout << dp[top] << endl;
            return;
        }
        if (!visited[top + 1])
        {
            if ((top + 1 >= 0) and (top + 1 <= x))
            {
                visited[top + 1] = true;
                dp[top + 1] = dp[top] + 1;
                qu.push(top + 1);
            }
        }
        if (!visited[top - 1])
        {
            if ((top - 1 >= 0) and (top - 1 <= x))
            {
                visited[top - 1] = true;
                dp[top - 1] = dp[top] + 1;
                qu.push(top - 1);
            }
        }
        if (!visited[top + y])
        {
            if ((top + y >= 0) and (top + y <= x))
            {
                visited[top + y] = true;
                dp[top + y] = dp[top] + 1;
                qu.push(top + y);
            }
        }
        if (!visited[top - y])
        {
            if ((top - y >= 0) and (top - y <= x))
            {
                visited[top - y] = true;
                dp[top - y] = dp[top] + 1;
                qu.push(top - y);
            }
        }
    }
}
int main()
{
    freopen("JUMP.inp", "r", stdin);
    freopen("JUMP.out", "w", stdout);
    cin >> n;
    while (n--)
    {
        cin >> x >> y;
        bfs(0, y, x);
    }
}
