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
map<ll,ll> b;
void solve(ll k)
{
    ll dem1 = 0;
    for (int i = 2; i <= sqrt(k); ++i)
    {
        if (k % i == 0)
        {
            ++dem1;
            ll dem = 0;
            while (k % i == 0)
            {
                ++dem;
                k /= i;
            }
            b[i] = dem;
        }
    }
    if(k > 1)
    {
        ++dem1;
        b[k] = 1;
    }
}
ll n;
int main()
{
    cin >> n;
    solve(n);
    cout << b.size() << '\n';
    for(auto x : b)
    {
        cout << x.fi << ' ' << x.se << '\n';
    }
}