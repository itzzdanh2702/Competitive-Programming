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
ll a, b;
int demuoc(ll u)
{
    ll ans = 0;
    for (int i = 1; i <= sqrt(u); ++i)
    {
        if (u % i == 0)
        {
            ll q = u / i;
            if (q == i)
            {
                ++ans;
            }
            else
            {
                ans += 2;
            }
        }
    }
    return ans;
}
int main()
{
    freopen("GCD.inp","r",stdin);
    freopen("GCD.out","w",stdout);
    FAST();
    cin >> TC;
    while (TC--)
    {
        ll x, y;
        cin >> x >> y;
        cout << demuoc(abs(x - y)) << endl;
    }
}