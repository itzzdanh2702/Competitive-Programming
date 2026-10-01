#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1000000007;
const ll inf = 0x3f;
const ll nmax = 1000005;
vector<int> a[nmax];
ll root[nmax], n, m, dem;

ll x,y,k;
ll kq = 1e18;

int findroot(int u)
{
    if (root[u] == u)
        return u;
    return root[u] = findroot(root[u]);
}
void mergeroot(int u, int v)
{
    int r1 = findroot(u);
    int r2 = findroot(v);
    if (r1 != r2)
        root[r1] = r2;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i=1;i<=1e5;i++)
    {
        root[i]=i;
    }
    for (ll i = 1; i <= n; i++)
    {
        ll x,y,k;
        cin>>x>>y>>k;
        if(k==1)
        {
            mergeroot(x,y);
        }
        else if (k==2)
        {
            if(findroot(x)==findroot(y))
            cout<<"1"<<endl;
            else cout<<"0"<<endl;
        }
    }
}