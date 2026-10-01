#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define nmax 1000000
ll a[1000][1000],m,n,u,v,trace[100005],k,dem=0,g,ans,ans1,ma=-1e9;
vector<ll> dinhke[100005];
vector<ll> vec;
vector<ll> vec1;
bool visited[100005];
void dfs(ll k)
{
  vec1.push_back(k);
  ans1++;
  visited[k]=true;
  for(int x:dinhke[k])
  {
    if(!visited[x])
    {
        //trace[x]=u; 
        dfs(x);
    }
  }
}

int main()
{
   cin>>n>>m;
   while(m--)
   {
    cin>>u>>v;
    dinhke[u].push_back(v);
    dinhke[v].push_back(u);
   }
  memset(visited,false,sizeof(visited));
  
  for(int i=1;i<=n;i++)
  {
    ans1=0;
    if(!visited[i])
    {
      
      dfs(i);
      ma=max(ma,ans1);
     
    }
  }
  cout<<ma<<endl;
  ll dem=0;
  memset(visited,false,sizeof(visited));
  for(int i=1;i<=n;i++){
    ans1=0;
    if(visited[i]==false){
      dfs(i);
      if(ma==ans1) dem++;
    }
  }
  cout<<dem<<endl;
  ll kq;
  memset(visited,false,sizeof(visited));
  for(int i=1;i<=n;i++)
  {
    ans1=0;
    vec1.clear();
    if(visited[i]==false){
      dfs(i);
      if(vec1.size()==ma) break;
    }
  }
  sort(vec1.begin(),vec1.end());
  for(auto it: vec1)
  {
    cout<<it<<" ";
  }
  /*while(visited[p])
  {
    p++;
    if(!visited[p])
    {
     dem++;
     dfs(p);

    }
  }
  */
}

