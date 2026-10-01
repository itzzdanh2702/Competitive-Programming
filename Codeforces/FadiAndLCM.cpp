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

ll n;
pair<ll, ll> ans;

pair<ll, ll> solve(ll n)
{
    for (ll i = 1; i <= sqrt(n); ++i)
    {
        if (n % i == 0)
        {
            if (__gcd(n / i, i) == 1)
            {
                ans = {i, n / i};
            }
        }
    }
    return ans; 
}
int main(int argc, char const *argv[])
{
    FAST();
    cin >> n;
    solve(n);
    cout << ans.fi << ' ' << ans.se;
    return 0;
}
