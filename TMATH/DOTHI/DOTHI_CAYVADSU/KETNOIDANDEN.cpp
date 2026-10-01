#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1000000007;
const ll inf = 0x3f;
const int arr = 1000005;
vector<int> a[arr];
int root[arr], n, m, dem;
ll kq=1e18;
int findroot(int u)
{
    if(root[u] == u)return u;
    return root[u] = findroot(root[u]);
}
void mergeroot(int u, int v)
{
    int r1 = findroot(u);
    int r2 = findroot(v);
    if(r1 != r2)root[r1] = r2;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    dem = n;
    for(int i = 1; i <= n; i++)
    {
        root[i] = i;
    }
    for(ll i = 1; i <= m; i++)
    {
        int u, v; cin >> u >> v;
        int r1 = findroot(u);
        int r2 = findroot(v);
        if(r1 != r2)
        {
            dem--;
            mergeroot(u, v);
        }
        if(dem==1)
        {
            kq=min(kq,i);
        }
    }
    if (kq==1e18) cout<<"FAILURE";
    else cout<<kq;

}