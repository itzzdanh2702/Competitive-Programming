#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 105
ll TC;
ll a[MAXN];
int main()
{
    cin >> TC;
    while(TC--)
    {
        ll kq = 0;
        ll S = 0;
        ll n,k;
        ll tmp1 = 0,tmp2 = 0;
        ll ans1 = 0,ans2 = 0;
        cin >> n >> k;
        for(int i = 1 ; i <= n ; ++i)
        {
            cin >> a[i];
            S += a[i];
        }
        sort(a + 1 , a + n + 1);
        for(int i = 1 ; i <= k ; ++i)
        {
            tmp1 += a[i];
        }
        ans1 = abs((S - tmp1)-tmp1);
        for(int i = n ; i > n - k ; --i)
        {
            tmp2 += a[i];
        }
        ans2 = abs((S - tmp2) - tmp2);
        kq = max(ans1,ans2);
        cout << kq << '\n';
    }
	return 0;
}
