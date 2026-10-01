#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nmax 1001
#define pii pair<ll, ll>
#define li pair<ll, pii>
#define fi first
#define se second
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
ll a[nmax][nmax];
ll dp[nmax][nmax];
pii ans;
bool visited[nmax][nmax];
ll m, n;
ll s, t;
ll mi = INF;
void FAST()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void dijiktra(ll x, ll y)
{
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dp[i][j] = INF;
        }
    }
    priority_queue<li, vector<li>, greater<li>> pq;
    dp[x][y] = a[x][y];
    pq.push({dp[x][y], {x, y}});
    visited[x][y] = true;
    while (!pq.empty())
    {
        li top = pq.top();
        pq.pop();
        for (int k = 0; k < 4; k++)
        {
            int i1 = top.se.fi + dx[k];
            int j1 = top.se.se + dy[k];
            if (!visited[i1][j1])
            {
                if ((i1 > 1) and (i1 < m) and (j1 > 1) and (j1 < n))
                {
                    if (dp[i1][j1] > dp[top.se.fi][top.se.se] + a[i1][j1])
                    {
                        dp[i1][j1] = dp[top.se.fi][top.se.se] + a[i1][j1];
                        visited[i1][j1] = true;
                        pq.push({dp[i1][j1], {i1, j1}});
                    }
                }
                else if ((i1 == 1) or (i1 == m) or (j1 == 1) or (j1 == n))
                {
                    if (dp[i1][j1] > dp[top.se.fi][top.se.se] + a[i1][j1])
                    {
                        dp[i1][j1] = dp[top.se.fi][top.se.se] + a[i1][j1];
                        ans = {i1, j1};
                        
                    }
                }
            }
        }
    }
}
int main()
{
    FAST();
    cin >> m >> n >> s >> t;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    if ((s == 1) or (s == m) or (t == 1) or (t == n))
        return cout << a[s][t], 0;
    dijiktra(s, t);
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if((i==1) or (i==m) or (j==1) or (j==n))
            {
                mi = min(mi,dp[i][j]);
            }
        }
    
    }
    cout<<mi;
}