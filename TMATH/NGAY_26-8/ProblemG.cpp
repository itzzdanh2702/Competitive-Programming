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
ll n, k;

ll legendere(ll n, ll k)
{
    ll ans = 0;
    while (n > 0)
    {
        ans += n / k;
        n /= k;
    }
    return ans;
}
int main()
{
    FAST();
    cin >> n >> k;
    cout << legendere(n, k) << '\n';
}