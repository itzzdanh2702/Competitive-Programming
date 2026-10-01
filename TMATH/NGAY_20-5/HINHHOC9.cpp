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

int main()
{
    ll x1, y1;
    ll x2, y2;
    FAST();
    cin >> TC;
    while (TC--)
    {
        cin >> x1 >> y1;
        cin >> x2 >> y2;
        ll tmp1 = y1 - y2;
        ll tmp2 = x2 - x1;
        ll tmp3 = x1 * (y2 - y1) + y1 * (x1 - x2);
        cout << tmp1 << ' ' << tmp2 << ' ' << tmp3 << '\n';
    }
}