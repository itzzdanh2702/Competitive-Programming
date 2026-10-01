#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define nmax 1000000
ll dx[]={-1,0,1,0};
ll dy[]={ 0,-1,0,1};
ll m,n,ans,S,t,ma=0;
ll p[1000][1000];
vector<ll> ans1,ans2;
int a[1000][1000];
bool visited[1000][1000],check[1000][1000];
void dfs(int i,int j)
{
    check[i][j]=true;
    S += a[i][j];
    visited[i][j]=true;
    for(int k=0;k<4;k++)
    {
        ll i1=i+dx[k];
        ll j1=j+dy[k];
        if((i1>=1) && (i1<=m) && (j1>=1) && (j1<=n))
        {
        if((!visited[i1][j1]) && (a[i1][j1] != 0))
        {
            dfs(i1,j1);
        }
    }
    }
}
int main()
{
    freopen("ROOM3.inp","r",stdin);
    freopen("ROOM3.out","w",stdout);
    cin >> m >> n;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>a[i][j];
        }
    }
    memset(visited,false,sizeof(visited));
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if((!visited[i][j]) && (a[i][j]!=0))
            {
                dfs(i,j);
                ma = max(ma , S);
                ans++;
                S=0;
            }
        }
    }
    cout << ma;
    return 0;
}
