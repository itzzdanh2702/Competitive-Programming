#include <bits/stdc++.h>
using namespace std;
#define ll long long
const long long MOD = 1000000007;
#define MAXN 2 * 1000005
#define oo 1000000000
void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll n, k;
ll a[MAXN];
ll store[11];
ll ans = 0;
vector<ll> vec[MAXN];

int chuso(ll n)
{
    ll dem = 0;
    while (n != 0)
    {
        ++dem;
        n /= 10;
    }
    return dem;
}
int main()
{
    FAST();
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= 10; ++i)
    {
        store[i] = (ll)pow(10, i) % k;
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= 10; ++j)
        {
            vec[j].push_back(((a[i] % k) * store[j]) % k);
        }
    }
    for (int i = 1; i <= 10; ++i)
    {
        sort(vec[i].begin(), vec[i].end());
    }
    for (int i = 1; i <= n; ++i)
    {
        int it1 = upper_bound(vec[chuso(a[i])].begin(), vec[chuso(a[i])].end(), (k - a[i] % k) % k) - vec[chuso(a[i])].begin();
        int it2 = lower_bound(vec[chuso(a[i])].begin(), vec[chuso(a[i])].end(), (k - a[i] % k) % k) - vec[chuso(a[i])].begin();
        if (((k - a[i] % k) % k) != ((a[i] % k) * ((ll)pow(10, chuso(a[i])) % k)) % k)
        {
            ans += it1 - it2;
        }
        else
        {
            ans += it1 - it2 - 1;
        }
    }
    cout << ans;
}