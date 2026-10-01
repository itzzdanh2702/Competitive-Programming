#include <bits/stdc++.h>
using namespace std;
#define ll long long
const long long MOD = 1000000007;
#define MAXN 1000005
#define oo 1000000000
void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll N,M;
ll a[MAXN],b[MAXN];
ll ma;

void chat()
{
    ll ma = -1;
    ll l = 1 , r = 1e18;
    ll ans = 0;
    while(l <= r)
    {
        ll kq = 0;
        ll mid = (l + r)/2;
        for(int i = 1 ; i <= N ; ++i)
        {
            kq += max(0LL,a[i] - mid/b[i]);
        }
        if(kq > M) 
        {
            l = mid + 1;
        }
        else 
        {
            r = mid - 1;
            ans = mid;
        }
    }
    cout << ans;
    
}
int main()
{
    cin >> N >> M;
    for(int i = 1 ; i <= N ; ++i)
    {
        cin >> a[i];
    }
    for(int i = 1 ; i <= N ; ++i)
    {
        cin >> b[i];
    }
    chat();
}