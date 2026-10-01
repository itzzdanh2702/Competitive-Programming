#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll k, x, b[30], kq, z, a[30];
ll th1(ll k, ll x)
{
    ll kq = 0;
    for (ll i = 1; i <= k; i++)
    {
        if (__gcd(i, x) == 1)
            kq++;
    }
    return kq;
}
void xl()
{
    ll tsnt = 1, stsnt = 0;
    for (int i = 1; i <= z; i++)
    {
        if (b[i])
        {
            tsnt *= a[i];
            stsnt++;
        }
    }
    if (tsnt != 1)
    {
        (stsnt % 2 == 0) ? kq += (k / tsnt) : kq -= (k / tsnt);
    }
}
void np(ll i)
{
    for (int j = 0; j <= 1; j++)
    {
        b[i] = j;
        if (i == z)
            xl();
        else
            np(i + 1);
    }
}
ll th2(ll k, ll x)
{
    ll tmp = x;
    for (int i = 2; i <= sqrt(tmp); i++)
    {
        if (tmp % i == 0)
        {
            a[++z] = i;
            while (tmp % i == 0)
                tmp /= i;
        }
    }
    if (tmp != 1)
        a[++z] = tmp;
    kq = k;
    np(1);
    return kq;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> x;
    k = x;
    if (k <= 1e6)
        cout << th1(k, x);
    else
        cout << th2(k, x);
}