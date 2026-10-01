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
ll ans;
ll f[60];

bool check(ll n)
{
    if (n < 2)
        return false;
    for (int i = 2; i <= sqrt(n); ++i)
        if (n % i == 0)
            return false;
    return true;
}
int main()
{
    FAST();
    f[0] = 0;
    f[1] = f[2] = 1;
    for (int i = 3; i <= 60; ++i)
    {
        f[i] = f[i - 1] + f[i - 2];
    }
    cin >> n;
    int it = 0;
    while (f[it] <= n)
    {
        if (check(f[it]))
        {
            ans = f[it];
            ++it;
        }
        else
            ++it;
    }
   // cout << f[50] << ' ';
    cout << ans;
}