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

ll a, b, c;
ll ma;
map<ll,ll> mp;
void solve(ll k)
{
    for (int i = 2; i <= sqrt(k); ++i)
    {
        if (k % i == 0)
        {
            ll dem = 0;
            while (k % i == 0)
            {
                ++dem;
                k /= i;
            }
            mp[i] += dem;
        }
    }
    if (k > 1)
    {
        mp[k] += 1;
    }
}
int main()
{
    cin >> a >> b >> c;
    solve(a);
    solve(b);
    solve(c);
    for(auto x : mp)
    {
        ma = __gcd(ma,x.se);
    }
    cout << ma;
}