#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=1e9+7;
const ll nmax=1e6+5;
int m,n,ans=0;
int main()
{
    freopen("SQUARE.inp","r",stdin);
    freopen("SQUARE.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin >> m >> n ;
	if (m == n)
    {
        cout << 0;
        return 0;
    }
	while ( m != 0 && n != 0 )
	{
	    int tmp = min ( m , n ) ;
	    int cmp = max ( m , n ) ;
	    m = cmp - tmp ;
	    n = tmp ;
	    ans++;
	    if ( m == 1 || n == 1 )
        {
            ans += max ( m , n ) - 1;
            break;
        }
	    if (m == n) break;
	}
	cout << ans ;
}
