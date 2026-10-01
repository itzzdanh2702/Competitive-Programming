#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define nmax 1000000
ll a[1000][1000],m,n,u,v,trace[1001],k,dem=0,g,tmp,res[1001],ans;
vector<ll> dinhke[1001];
bool visited[1001],check;
void xuat()
{
    for(int i=0;i<ans;i++) cout<<res[i]<<' ';
    cout<<endl;
}
void dfs(int u)
{
    visited[u]=true;
    res[ans++]=u;
    for(auto x: dinhke[u])
    {
        if(ans==k+1)
        {
        xuat();
        break;
        }
        if(!visited[x])
        {
            dfs(x);
            ans--;
            visited[x]=0;
        }
    }
    //if(check==1)
    //xuat();
}

int main()
{
   freopen("PATH2.inp","r",stdin);
   freopen("PATH2.out","w",stdout);
   cin>>n>>m>>g>>k;
   while(m--)
   {
    cin>>u>>v;
    dinhke[u].push_back(v);
    dinhke[v].push_back(u);
   }
   memset(visited,false,sizeof(visited));
   dfs(g);
  //for(auto x:dinhke[3])
  //cout<<x;
 

}

