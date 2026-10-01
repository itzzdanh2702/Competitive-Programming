#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define pii pair<ll, ll>
const long long MOD = 1000000007;
#define MAXN 1000005
#define oo 1000000000
void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll ma = -oo;
ll a[MAXN];
int n,m;

bool check(ll mid)
{
    ll S = 0;
    for(int i = 1 ; i <= n ; ++i)
    {
        if(a[i] > mid)
        {
            S += a[i] - mid;
        }
    }
    return S >= m;
}
int main()
{
    cin >> n >> m;
    for(int i = 1 ; i <= n ; ++i)
    {
        cin >> a[i]; 
        ma = max(ma,a[i]);
    }
    ll l = 1 , r = ma - 1;
    ll ans;
    while(l <= r)
    {
        ll mid = (l + r)/2;
        if(check(mid))
        {
            l = mid + 1;
            ans = mid;
        }
        else 
        {
            r = mid - 1;
        }
    }
    cout << ans;
}