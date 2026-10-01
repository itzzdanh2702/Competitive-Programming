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
ll a[100];
ll arr[100];
ll cnt = 0;
vector<pii> v, v1;
bool cmp(pii x, pii y)
{
    if (x.fi != y.fi)
    {
        return x.fi < y.fi;
    }
    else
    {
        return x.se < y.se;
    }
}
void xuat()
{
    ll S = 0, P = 0;
    for (int i = 1; i <= n / 2; ++i)
    {
        if (a[i] == 1)
        {
            S += arr[i];
        }
        else
        {
            P += arr[i];
        }
    }
    v.push_back({S, P});
}

void quaylui(ll k)
{
    for (int i = 0; i <= 1; ++i)
    {
        a[k] = i;
        if (k == n / 2)
        {
            xuat();
        }
        else
        {
            quaylui(k + 1);
        }
    }
}
void xuat1()
{
    ll S = 0, P = 0;
    for (int i = n - n / 2; i <= n; ++i)
    {
        if (a[i] == 1)
        {
            S += arr[i];
        }
        else
        {
            P += arr[i];
        }
    }
    v1.push_back({S, P});
}

void quaylui1(ll k)
{
    for (int i = 0; i <= 1; ++i)
    {
        a[k] = i;
        if (k == n)
        {
            xuat1();
        }
        else
        {
            quaylui1(k + 1);
        }
    }
}
void xuat2()
{
    ll S = 0, P = 0;
    for (int i = n - n / 2 + 1; i <= n; ++i)
    {
        if (a[i] == 1)
        {
            S += arr[i];
        }
        else
        {
            P += arr[i];
        }
    }
    v1.push_back({S, P});
}

void quaylui2(ll k)
{
    for (int i = 0; i <= 1; ++i)
    {
        a[k] = i;
        if (k == n)
        {
            xuat2();
        }
        else
        {
            quaylui2(k + 1);
        }
    }
}
int main()
{
    FAST();
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> arr[i];
    }
    quaylui(1);
    if (n % 2 == 1)
    {
        quaylui1(n - n / 2);
    }
    else
    {
        quaylui2(n - n / 2  + 1);
    }
    ll mi = oo;
    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < v1.size(); ++i)
    {
        ll l = 0, r = v.size() - 1;
        while (l <= r)
        {
            ll mid = (l + r) / 2;
            if (v1[i].fi - v1[i].se + v[mid].fi - v[mid].se < 0)
            {
                mi = min(mi, abs(v1[i].fi - v1[i].se + v[mid].fi - v[mid].se));
                l = mid + 1;
            }
            else
            {
                mi = min(mi, v1[i].fi - v1[i].se + v[mid].fi - v[mid].se);
                r = mid - 1;
            }
        }
    }
    cout << mi;
}