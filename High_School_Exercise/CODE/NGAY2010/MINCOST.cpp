#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define nmax 1000000
#define mod 1000000007
ll m,n,a[2000][2000],mi;
int main()
{
    freopen("MINCOST.inp","r",stdin);
    freopen("MINCOST.out","w",stdout);
    cin>>m>>n;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>a[i][j];
        }
    }
     for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            mi=min(a[i-1][j],a[i][j-1]);
            a[i][j]+=mi;
        }
    }
    cout<<a[m][n];

}
