#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define pii pair<ll, ll>
const long long MOD = 1000000007;
#define MAXN 1000005
#define oo 1000000000
const ll limit = 5 * 1e6;
void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

bool nt[limit];
void sang()
{
    memset(nt, true, sizeof(nt));
    nt[0] = nt[1] = false;
    for (int i = 2; i <= sqrt(limit); ++i)
    {
        if (nt[i])
        {
            for (int j = i * i; j <= limit; j += i)
            {
                nt[j] = false;
            }
        }
    }
}
ll legendere(ll m)
{
    ll S = 0;
    vector<ll> v;
    for (int i = 2; i <= m; ++i)
    {
        if (nt[i])
        {
            v.push_back(i);
        }
    }
    for (int i = 0; i < v.size(); ++i)
    {
        ll tmp = m;
        ll dem = 0;
        while (tmp > 0)
        {
            dem += tmp / v[i];
            tmp /= v[i];
        }
        S += dem;
    }
    return S;
}
int TC;
ll store[5 * 1000001];
ll a, b;
int main()
{
    FAST();
    sang();
    cin >> TC;
    while (TC--)
    {
        cin >> a >> b;
        cout << legendere(a) - legendere(b) << '\n';
    }
}

/*

*/