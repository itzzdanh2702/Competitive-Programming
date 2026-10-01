#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define nmax 1000000
const ll INF = 1e18;
ll a[1001][1001];
ll t;
ll n,m;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            a[i][j] = INF;
        }
    }
    while(m--)
    {
        ll u,v,w,dist;
        cin>>u>>v>>w>>dist;
        if(dist == 0)
        {
            a[u][v] = w;
            a[v][u] = w;
        }
        else if(dist == 1)
        {
            a[u][v] = w;
        }
    }
    for(int i=1;i<=n;i++)
        a[i][i] = 0;
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if((a[i][k]!=0) and (a[k][j]!=0) and (a[i][k]!=INF) and (a[k][j]!=INF))
                {
                    if(a[i][j]>a[i][k]+a[k][j])
                    {
                        a[i][j] = a[i][k] + a[k][j];
                    }
                }
            }
        }
    }
    cin>>t;
    while(t--)
    {
        int p,q;
        cin>>p>>q;
        if((a[p][q]!=INF) and (a[p][q]!=0))
        {
            cout<<a[p][q]<<endl;
        }
        else
        {
            cout<<"-1"<<endl;
        }
    }


}
