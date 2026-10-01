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

ll TC;
ll n;
ll a[MAXN];
ll cnt[MAXN];

int main()
{
    FAST();
    cin >> TC;
    while(TC--)
    {
        ll ans = 0;
        cin >> n;
        for(int i = 1 ; i <= n ; ++i)
        {
            cnt[i] = 1;
        }
        for(int i = 1 ; i <= n ; ++i)
        {
            cin >> a[i];
        }
        for(int i = 2 ; i <= n ; ++i)
        {
            if(a[i] >= a[i - 1])
            {
                cnt[i] = cnt[i - 1] + 1; 
            }
            else 
            {
                cnt[i] = 1;
            }
        }
        for(int i = 1 ; i <= n ; ++i)
        {
            ans += cnt[i];
        }
        cout << ans << '\n';

    }
}