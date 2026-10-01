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

ll a, b;
ll ans = 0;

int chuso(int n)
{
    int dem = 0;
    while (n > 0)
    {
        ++dem;
        n /= 10;
    }
    return dem;
}

int tong(ll n)
{
    ll S = 0;
    while (n > 0)
    {
        S += n % 10;
        n /= 10;
    }
    return S;
}

ll tong1(int n)
{
    return n * (n + 1) / 2;
}
int main()
{
    FAST();
    cin >> a >> b;
    ll tmp1 = 0, tmp2 = 0;
    ll tmp = a;
    bool check = 0;
    while (!check)
    {
        int dem = 0;
        if (chuso(tmp) == 1)
        {
            check = 1;
            tmp1 += tong(tmp);
        }
        else
        {
            tmp = tong(tmp);
        }
    }
    tmp = b;
    check = 0;
    while (!check)
    {
        int dem = 0;
        if (chuso(tmp) == 1)
        {
            check = 1;
            tmp2 += tong(tmp);
        }
        else
        {
            tmp = tong(tmp);
        }
    }
    ll dist = (b - a - tmp2 - 10 + tmp1 + 1) / 9;
    ans = 45 * dist;
    if (ans == 0)
        cout << 45 - tong1(tmp1 - 1) + tong1(tmp2);
    else
        cout << 45 - tong1(tmp1 - 1) + tong1(tmp2) + ans;
}