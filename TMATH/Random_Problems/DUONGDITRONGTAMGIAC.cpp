#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define nmax 100
ll n,a[100][100],ma=-100000;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            cin>>a[i][j];
        }
    }
     for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            if((i==1) and (j==1)) a[i][j]=a[i][j];
            else if((i!=1) and (j==1)) a[i][j]+=a[i-1][j];
            else if (i==j) a[i][j]+=a[i-1][j-1];
            else a[i][j]+=max(a[i-1][j-1],a[i-1][j]);


        }
}
for(int j=1;j<=n;j++)
    ma=max(ma,a[n][j]);
cout<<ma;
}
