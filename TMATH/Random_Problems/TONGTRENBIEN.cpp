#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define nmax 1000000
ll a[1000][1000],n,S;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
          if((i==1) or (j==1)) S+=a[i][j];
        }
    }

    cout<<S;
}
