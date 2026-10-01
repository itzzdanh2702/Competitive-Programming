#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll a[1000][1000],n,m,t,x,y,p,q,S[1000][1000];
int main()
{
    cin>>m>>n>>t;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>a[i][j];

        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            S[j][i]=S[j-1][i]+a[j][i];
        }
    }
    while(t--)
    {
        ll sum=0,d=0,s=0;
        cin>>x>>y>>p>>q;
        for(int i=1;i<=q;i++)
            sum+=S[p][i];
            for(int i=y;i<=q;i++)
                s+=S[x-1][i];
            for(int i=1;i<=y-1;i++)
                d+=S[p][i];
            cout<<sum-s-d<<endl;
    }


}
