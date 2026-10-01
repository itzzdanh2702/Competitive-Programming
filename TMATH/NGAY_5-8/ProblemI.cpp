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

ll l, r, t;
ll ans;
int main(int argc, char const *argv[])
{
    FAST();
    cin >> l >> r >> t;
    ll tmp = (t + 1) / 2;
    ll tmp1 = min(r - tmp + 1, t - tmp - l + 1);
    tmp1 = max(0LL, tmp1);
    ll tmp2 = min(r - t + 1, 0 - l + 1);
    tmp2 = max(0LL, tmp2);
    ans = tmp1 + tmp2;
    cout << ans;
    return 0;
}