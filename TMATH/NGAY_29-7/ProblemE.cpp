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

ll a, b, c;
ll ans = 0;

int main()
{
    FAST();
    cin >> a >> b >> c;
    if (a & 1)
    {
        ans += (a + 1) / 2;
    }
    else
    {
        ans += a / 2;
    }
    if (b & 1)
    {
        ans += (b + 1) / 2;
    }
    else
    {
        ans += b / 2;
    }
    if (c & 1)
    {
        ans += (c + 1) / 2;
    }
    else
    {
        ans += c / 2;
    }
    cout << ans;
}