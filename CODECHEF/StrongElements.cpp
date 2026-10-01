#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define pii pair<ll, ll>
const long long MOD = 1000000007;
#define MAXN 3 * 100005
#define oo 1000000000

void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int TC;
int n;
int a[MAXN];
int pre[MAXN];
int suffix[MAXN];

void solve()
{
    ll cnt = 0;
    cin >> n;
    for(int i = 1 ; i <= n ; ++i)
    {
        cin >> a[i];
    }
    pre[1] = a[1];
    suffix[n] = a[n];
    for(int i = 2 ; i <= n ; ++i)
    {
        pre[i] = __gcd(pre[i - 1],a[i]);
    }
    for(int i = n - 1 ; i >= 1 ; --i)
    {
        suffix[i] = __gcd(suffix[i + 1],a[i]);
    }
    for(int i = 1 ; i <= n ; ++i)
    {
        if(i == 1)
        {
            if(suffix[i + 1] != 1)
            {
                ++cnt;
                continue;
            }
        }
        if(i == n)
        {
            if(pre[i - 1] != 1)
            {
                ++cnt;
                continue;
            }
        }
        if(__gcd(pre[i - 1],suffix[i + 1]) != 1)
        {
            ++cnt;
        }
    }
    cout << cnt << '\n';
}
int main()
{
    FAST();
    cin >> TC;
    while(TC--)
    {
        solve();
    }

}

