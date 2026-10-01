 #include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define nmax 1000000
#define pii pair<ll,ll>
#define fi first
#define se second 


ll n,m,p,x,s,t;
ll a[nmax],d[nmax];

vector<pii> dinhke[nmax];
queue<ll> qu;

void bfs(int u)
{
  d[u]=0;
  qu.push(u);
  while(!qu.empty())
  {
    ll tmp=qu.front();
    qu.pop();
    for(auto it:dinhke[tmp])
    { 
        if ((it.se>=x) and (d[it.fi]==1e18))
        {
            d[it.fi]=0;    
            qu.push(it.fi); 
            if(it.fi==t) return;
        }
       
    }
  }
}
int main()
{
    cin>>m>>n>>x>>s>>t;
    while(n--)
    {
        ll u,v,w;
        cin>>u>>v>>w;
        dinhke[u].push_back({v,w});
        dinhke[v].push_back({u,w});
    }
    fill(d,d+nmax,1e18);
    bfs(s);
    if(d[t]==1e18) cout<<"NO";
    else cout<<"YES";
   

}