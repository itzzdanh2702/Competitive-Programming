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

ll l, r, a, k;
ll cnt = 0;

void sub1()
{
    for (int i = l; i <= r; ++i)
    {
        if ((a * i) % k == 0)
        {
            ++cnt;
        }
    }
    cout << cnt << ' ';
}

void sub2()
{
    //(a * s) % k == 0
    //(2 * s) % 4 = 0;
    // 2 4 6 8 10
    // (2 * s) % 6 = 0;
    // (x * y)/__gcd(x,y)/x = y/__gcd(x,y)

    ll p = k / __gcd(k, a);
    if (p >= l)
    {
        l = p;
        if (p <= r)
        {
            r = r - r % p;
        }
        else
        {
            cout << cnt;
            return;
        }
    }
    else
    {
        ll tmp1 = (l / p) + 1;
        ll l = tmp1 * p;
        if (tmp1 * p > r)
        {
            cout << cnt;
            return;
        }
        else
        {
            r = r - r % p;
        }
    }
    cout << (r - l) / p + 1;
}
int main(int argc, char const *argv[])
{
    FAST();
    cin >> l >> r >> a >> k;
    //sub1();
    sub2();
    return 0;
}