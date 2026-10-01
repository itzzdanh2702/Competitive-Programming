#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll m,n,q,a[1005][1005],x[10000000],pos[10000000],pos1[10000000],d=1;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>m>>n>>q;
    for (ll i=1;i<=m;i++)
    {
        for (ll j=1;j<=n;j++)
            cin>>a[i][j],pos[a[i][j]]=i,pos1[a[i][j]]=j;
    }
    for (ll i=1;i<=q;i++)
        cin>>x[i];
    for (ll i=1;i<=q;i++)
    {
        if (pos[x[i]]!=0&&pos1[x[i]]!=0)
        cout<<pos[x[i]]<<' '<<pos1[x[i]]<<'\n';
        else cout<<-1<<'\n';
    }
}
