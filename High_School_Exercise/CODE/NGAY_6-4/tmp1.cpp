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

int a, m, b, n, k;
int TC; 

ll mul(int a, int n, int mod)
{
    if (n == 0)
        return 1;
    ll tmp = mul(a, n / 2, mod);
    if (n % 2 == 0)
        return ((tmp % mod) * (tmp % mod)) % mod;
    else
        return ((((tmp % mod) * (tmp % mod)) % mod) * (a % mod)) % mod;
}

int main()
{
    FAST();
    cin >> TC;
    while (TC--)
    {
        cin >> a >> m >> b >> n >> k;
        cout << mul(a,m,k) << '\n';  
    }
}