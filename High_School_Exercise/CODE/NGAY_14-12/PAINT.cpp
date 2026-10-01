#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll nmax = 2005;
ll m,n,a[nmax][nmax],ans;
int main()
{
    //freopen("PAINT.inp","r",stdin);
    //freopen("PAINT.out","w",stdout);
    ios_base::sync_with_stdio(0) ;
    cin.tie(0) , cout.tie(0) ;
    cin >> m >> n;
    for (int i = 1 ; i <= m ; i++)
    {
        for (int j = 1 ; j <= n ; j++)
            cin >> a[i][j];
    }
    for (int i = 1 ; i <= m ; i++)
    {
        for (int j = 1 ; j <= n ; j++)
        {
            if (a[i][j] > a[i-1][j])
                ans += a[i][j] - a[i-1][j];
            if (a[i][j] > a[i][j-1])
                ans += a[i][j] - a[i][j-1];
            if (a[i][j] > a[i+1][j])
                ans += a[i][j] - a[i+1][j];
            if (a[i][j] > a[i][j+1])
                ans += a[i][j] - a[i][j+1];
        }
    }
    cout << ans;
    return 0;
}