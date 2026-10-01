#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define pii pair<ll,ll>
#define fi first 
#define se second 
const long long MOD = 1000000007;
#define MAXN 1000005
#define oo 1000000000
void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
ll m,n;
ll dem;
ll a[1005][1005];
vector<pii> v;

int main()
{
    FAST();
    freopen("MOUNTAIN.inp","r",stdin);
    freopen("MOUNTAIN.out","w",stdout);
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
            if((a[i][j]>a[i-1][j]) and (a[i][j]>a[i+1][j]) and (a[i][j]>a[i][j-1]) and (a[i][j]>a[i][j+1]))
            {
                v.push_back({i,j});
            }
        }
    }
    cout<<v.size()<<endl;
    for(auto x:v)
    {
        cout<<x.fi<<' '<<x.se<<endl;
    }
}
