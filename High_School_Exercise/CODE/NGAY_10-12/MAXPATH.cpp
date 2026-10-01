#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define nmax 1000000
const ll oo 1e18;
ll n,m;
ll w[1001][1001];
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            w[i][j]=oo;
        }
    }
    for(int i=1;i<=n;i++)
    w[i][i]=0;
    while(m--)
    {
        ll u,v,thir;
        cin>>u>>v>>thir;
        w[u][v]=thir;
        w[v][u]=thir;
    }
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int i=1;i<=n;i++)
            {
                if((w[i][k]!=oo) and (w[k][j]!+oo))
            }
        }
    }
}