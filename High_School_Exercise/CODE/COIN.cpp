#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=1e9+7;
const ll nmax=1e6+5;
int n,x,a[nmax],f[nmax],dem=0;
int main()
{
    freopen("COIN.INP","r",stdin);
    freopen("COIN.OUT","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin >> n >> x;
    for (int i=0 ; i<n ; i++) cin >> a[i];
    for (int i=1 ; i<=x ; i++) f[i]=1e18;
    for (int i=1 ; i<=x ; i++)
    {
        for (int j=0 ; j<n ; j++)
        {
            if (a[j]<=i && f[i-a[j]] + 1 <= f[i])
                f[i] = f[i-a[j]] + 1;
        }
    }
    if (f[x] != 1e18) cout << f[x];
    else cout << -1;
}
