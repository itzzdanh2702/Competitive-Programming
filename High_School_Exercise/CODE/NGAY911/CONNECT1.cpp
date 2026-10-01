#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define nmax 1000000
ll a[1000][1000],m,n,u,v,trace[1001],k,dem=0,g,tmp;
vector<ll> dinhke[1001];
vector<ll> ans;
bool visited[1001];
void dfs(int k)
{
  cout<<k<<' ';
  visited[k]=true;
  for(int x:dinhke[k])
  {
    if(!visited[x])
    {
        trace[x]=u;
        dfs(x);
    }
  }
}
int main()
{
  freopen("CONNECT1.inp","r",stdin);
  freopen("CONNECT1.out","w",stdout);
   cin>>n>>m;
   while(m--)
   {
    cin>>u>>v;
    dinhke[u].push_back(v);
    dinhke[v].push_back(u);
   }
  memset(visited,false,sizeof(visited));
  dfs(1);
  for(int i=1;i<=n;i++)
  {
   if(!visited[i])
   {
    cout<<endl;
    dfs(i);
   }
  }
}

