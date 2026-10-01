#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nmax 1000000
ll a[nmax], n, m, p, pos[nmax], dem;
vector<ll> dinhke[1000000], s;
queue<ll> qu;
bool check[1000000];
void bfs(int u)
{
  check[u] = 1;
  qu.push(u);
  while (!qu.empty())
  {
    ll tmp = qu.front();
    qu.pop();
    for (auto x : dinhke[tmp])
    {
      if (check[x])
        continue;
      else
      {
        dem++;
        pos[x] = dem;
        check[x] = 1;
        qu.push(x);
      }
    }
  }
}
int main()
{

  cin >> m >> n;
  while (n--)
  {
    ll u, v;
    cin >> u >> v;
    dinhke[u].push_back(v);
  }
  bfs(1);
  for (int i = 2; i <= m; i++)
    {
      if(pos[i]==0) cout<<"-1"<<' ';
      else cout<<pos[i]<<' ';
    }
}