  #include<bits/stdc++.h>
  using namespace std;
  #define ll long long 
  #define nmax 1000000
  ll a[nmax],n,m,p,q,trace[100001],k;
  vector<ll> dinhke[100001];
  queue<ll> qu;
  deque<ll> de;

  bool check[1001];
  void bfs(int u)
  {
    check[u]=1;
    qu.push(u);
    while(!qu.empty())
    {
      ll tmp=qu.front();
      qu.pop();
      
      for(auto x:dinhke[tmp])
      {
          if(check[x])
          continue;
          else 
          {
          trace[x]=tmp;
          check[x]=1;
          qu.push(x);
          }
      }
    }
  }
  int main()
  {
    
      cin>>m>>n>>q>>k;
      while(n--)
      {
          ll u,v;
          cin>>u>>v;
          dinhke[u].push_back(v);
          dinhke[v].push_back(u);
      }
      bfs(q);
    if(check[k]==true)
    {
      while(q!=k)
    {
      de.push_back(k);
      k=trace[k];
    }
    de.push_back(k);
    while(!de.empty())
    {
      cout<<de.back()<<" ";
      de.pop_back();
    }
    }
    else cout<<"-1";

    

  }