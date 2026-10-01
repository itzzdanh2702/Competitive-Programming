#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define nmax 1000000
ll dx[]={-1,0,1,0};
ll dy[]={ 0,-1,0,1};
ll m,n,ans,socuu,sosoi,t,kq,kq1,kq2;
ll p[1000][1000];
vector<ll> ans1;
char a[1000][1000];
bool visited[1000][1000],check[1000][1000];


void dfs(int i,int j)
{
    visited[i][j]=true;
    for(int k=0;k<4;k++)
    {
        ll i1=i+dx[k];
        ll j1=j+dy[k];
        if((i1>=1) and (i1<=m) and (j1>=1) and (j1<=n-1))
        {
        if(!visited[i1][j1])
        {
           if(a[i1][j1]!='*')
           {
            if(a[i1][j1]=='S')
            {
                socuu+=1;
                dfs(i1,j1);
            }
            else if (a[i1][j1]=='W')
            {
                sosoi+=1;
                dfs(i1,j1);
            }
            else if (a[i1][j1]=='.')
            {
                dfs(i1,j1);
            }

            }
            else 
            {
                continue;
            }
    
        }
        }
    }
}
int main()
{
    cin>>m>>n;
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
            if((a[i][j]!='*') and (!visited[i][j]))
            {
                if(a[i][j]=='S') socuu++;
                else if(a[i][j]=='W') sosoi++;
                dfs(i,j);
                if(socuu>sosoi)
                {
                    kq1+=socuu;
                    socuu=0;
                    sosoi=0;
                }
                else 
                {
                    kq2+=sosoi;
                    socuu=0;
                    sosoi=0;
                }
            }
        }
    }
    cout<<kq1<<' '<<kq2;
    //cout<<ans;
}
