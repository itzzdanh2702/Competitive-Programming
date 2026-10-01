#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define fi first
#define se second
const ll mod=1e9+7;
const ll nmax=1e6+5;
int n,x,a[nmax],dem=0,g[nmax],c[nmax];
pair<ll,ll> f[nmax];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin >> n >> x;
    for (int i=0 ; i<n ; i++) cin >> a[i];
    for (int i=1 ; i<=x ; i++) f[i].fi=LONG_MAX;
    for (int i=1 ; i<=x ; i++)
    {
        for (int j=1 ; j<=n ; j++)
        {
            if (a[j]<=i && f[i-a[j]].fi + 1 <= f[i].fi)
                {
                    f[i].fi = f[i-a[j]].fi + 1;
                    f[i].se=a[j];

                }

        }

    }
   while(x>0)
   {
    c[f[x].se]++;
    x-=f[x].se;
   }
   for(int i=1;i<=n;i++)
   {
    cout<<c[a[i]]<<" ";
    c[a[i]]=0;
   }

}
