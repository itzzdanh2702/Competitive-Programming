#include <bits/stdc++.h>

using namespace std;
#define ll long long
const int mod = 1e9 + 7;
const int N = 21;

void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll a,b;

ll POW(ll a,ll b,ll MOD)
{
    if(b == 0)
        return 1;
    ll tmp = POW(a,b/2,MOD - 2);
    if(b % 2 == 0)
        return ((tmp % MOD)* (tmp % MOD)) % MOD;
    else
        return ((((tmp % MOD) * (tmp % MOD)) % MOD) * (a % MOD)) % MOD;
}

int main()
{
    FAST();
    //freopen("code.inp","r",stdin);
    //freopen("code.out","w",stdout);
    cin >> a >> b;
    cout << POW(a,b,mod - 2);
}
