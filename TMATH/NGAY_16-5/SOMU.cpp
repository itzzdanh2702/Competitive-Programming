#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define pii pair<ll, ll>
const long long MOD = 1000000007;
#define MAXN 1000005
#define oo 1000000000000000
void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll n, k;
ll mi = oo;
map<ll, ll> dem;
vector<ll> v, v1;

ll legendre(ll m, ll val)
{
    ll tmp = 0;
    while (m > 0)
    {
        tmp += m / val;
        m /= val;
    }
    return tmp;
}
void solve(ll k)
{
    ll tmp = k;
    for (int i = 2; i <= sqrt(k); ++i)
    {
        if (tmp % i == 0)
        {
            while (tmp % i == 0)
            {
                v.push_back(i);
                tmp /= i;
            }
        }
    }
    if (tmp > 1)
    {
        v.push_back(tmp);
    }
}
int main()
{
    FAST();
    cin >> n >> k;
    solve(k);
    for (auto x : v)
    {
        ++dem[x];
    }
    for (auto x : dem)
    {
        ll tmp1 = legendre(n, x.fi);
        ll tmp2 = tmp1/x.se;
        mi = min(mi,tmp2);
    }
    cout << mi;
}   