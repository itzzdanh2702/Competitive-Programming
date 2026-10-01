#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define nmax 1000000
#define mod 1000000007
ll m,n,a[2000][2000],ma;
int main()
{
    freopen("THAMLAM.inp","r",stdin);
    freopen("THAMLAM.out","w",stdout);
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
            ma=max(a[i-1][j],max(a[i-1][j-1],a[i][j-1]));
            a[i][j]+=ma;
        }
    }
    cout<<a[m][n];

}
