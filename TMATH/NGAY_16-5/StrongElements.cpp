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
int n;
ll a[MAXN];
map<ll, ll> dp;

void solve(ll k)
{
    ll dem1 = 0;
    for (int i = 2; i <= sqrt(k); ++i)
    {
        if (k % i == 0)
        {
            while (k % i == 0)
            {
                k /= i;
            }
            ++dp[i];
        }
    }
    if (k > 1)
    {
        ++dp[k];
    }
}
int main()
{
    cin >> TC;
    while (TC--)
    {
        ll ma;
        cin >> n;
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i];
            ma = __gcd(ma, a[i]);
            solve(a[i]);
        }
        if(ma > 1)
        {
            cout << n << '\n';
        }
    }
}