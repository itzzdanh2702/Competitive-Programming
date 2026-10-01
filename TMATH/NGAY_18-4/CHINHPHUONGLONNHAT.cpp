#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define pii pair<ll, ll>
const long long MOD = 1000000007;
#define MAXN 10000005
#define oo 1000000000
void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll n;
ll ans = 1;
bool nt[MAXN];

ll POW1(int a,int n)
{
    ll ans = 1;
    for(int i = 1 ; i <= n ; ++i)
    {
        ans *= a;
        ans %= MOD;
    }
    return ans;
}
void sang()
{
    nt[0] = nt[1] = false;
    for (int i = 2; i <= sqrt(MAXN); ++i)
    {
        if (nt[i])
        {
            for (int j = i * i; j <= MAXN; j += i)
            {
                nt[j] = false;
            }
        }
    }
}
int main()
{
    FAST();
    cin >> n;
    memset(nt, true, sizeof(nt));
    sang();
    for (int i = 1; i <= n; ++i)
    {
        if (nt[i])
        {
            ll dem = 0;
            ll tmp = n;
            while (tmp > 0)
            {
                dem += tmp / i;
                tmp /= i;
            }
            if (dem > 0)
            {
                if (dem % 2 == 0)
                {
                    ans = ((ans % MOD) * ((ll)POW1(i, dem) % MOD)) % MOD;
                }
                else
                {
                    ans = ((ans % MOD) * ((ll)POW1(i, dem - 1) % MOD)) % MOD;
                }
            }
        }
    }
    cout << (ans + MOD) % MOD;
}