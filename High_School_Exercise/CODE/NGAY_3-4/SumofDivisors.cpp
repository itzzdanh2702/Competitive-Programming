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
    
ll n;
ll S = 0;
ll tong(ll x)
{
    return (((x % MOD) * ((x + 1) % MOD))/2) % MOD;
}
int main()
{
    FAST();
    cin >> n;
    ll i = 1;
    while (i <= n)
    {
        ll tmp = n / i;
        ll tmp1 = n / tmp;
        ll tmp3;
        if (tmp1 > i)
        {
            tmp3 = ((tmp % MOD) * (tong(tmp1) - tong(i - 1) + MOD)) % MOD;
            i = tmp1 + 1;
        }
        else
        {
            tmp3 = ((tmp % MOD) * (i % MOD)) % MOD;
            ++i;
        }
        tmp3 %= MOD;
        S += tmp3;
        S %= MOD;
    }
    cout << S;
}