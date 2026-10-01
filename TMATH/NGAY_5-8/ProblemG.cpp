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

ll l, r;

int main(int argc, char const *argv[])
{
    FAST();
    cin >> l >> r;
    ll r1 = r - r % 13;
    ll tmp = l % 13;
    ll l1 = l + (13 - tmp);
    ll tmp1 = (r1 - l1) / 13 + 1;
    cout << ((l + r) * (r - l + 1))/2 - ((r1 + l1) * tmp1) / 2;
    return 0;
}
