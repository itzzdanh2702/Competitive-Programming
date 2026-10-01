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

int TC;
ll a, b;
int n;

ll lcm(ll a, ll b)
{
    return (a * b) / __gcd(a, b);
}
int main()
{
    FAST();
    cin >> TC;
    while (TC--)
    {
        ll cnt = 1;
        ll x = 0, y = 1;
        cin >> n;
        for (int i = 1; i <= n; ++i)
        {
            cin >> a >> b;
            y = lcm(y, b);
            x = __gcd(x, a * b);
            if (x % y != 0)
            {
                ++cnt;
                x = a * b;
                y = b;
            }
        }
        cout << cnt << '\n';
    }
}