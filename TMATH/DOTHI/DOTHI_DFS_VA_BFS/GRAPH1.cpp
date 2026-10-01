#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define nmax 1000000
ll n,m;
ll a[1001][1001];
int main()
{ 
    cin>>n>>m;
    while(m--)
    {
        ll u,v;
        cin>>u>>v;
        a[u][v]=1;
        a[v][u]=1;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}