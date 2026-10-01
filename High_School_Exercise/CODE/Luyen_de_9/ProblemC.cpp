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

ll n, k;
ll ans = 0;

int main()
{
    FAST();
    cin >> n >> k;
    while (k % 2 == 1)
    {
        k = k / 2 + 1;
        ans += n / 2;
        n -= n / 2;
    }
    ans += k / 2;
    cout << ans;
}