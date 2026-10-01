#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll, ll>
#define fi first
#define se second
const ll nmax = 1e6 + 6;
ll dx[] = {-1, 0, 1, 0};
ll dy[] = {0, -1, 0, 1};
ll m, n;
ll dp[1001][1001];
vector<ll> ans1;
int a[1000][1000];
bool visited[1000][1000];

void bfs(int p, int q)
{
   dp[p][q] = 1 - a[p][q];
   visited[p][q] = true;
   queue<pii> qu;
   qu.push({p, q});
   while (!qu.empty())
   {
      pii top = qu.front();
      qu.pop();    
      if (((dp[top.fi][top.se] + a[top.fi][top.se]) % 2 == 0))
      {
         dp[top.fi][top.se] += 1;
         qu.push({top.fi, top.se});
      }
      else
      {
         for (int k = 0; k < 4; k++)
         {
            ll i1 = top.fi + dx[k];
            ll j1 = top.se + dy[k];
            if ((i1 >= 1) and (i1 <= m) and (j1 >= 1) and (j1 <= n))
            {
               if (!visited[i1][j1])
               {
                  dp[i1][j1] = dp[top.fi][top.se] + 1;
                  qu.push({i1, j1});
                  visited[i1][j1] = true;
                  
               }
            }
         }
      }
   }
}
int main()
{
   freopen("BRGAME.inp", "r", stdin);
   freopen("BRGAME.out", "w", stdout);
   cin >> m >> n;
   for (int i = 1; i <= m; i++)
   {
      for (int j = 1; j <= n; j++)
      {
         cin >> a[i][j];
      }
   }
   bfs(1, 1);
   cout << dp[m][n];
}