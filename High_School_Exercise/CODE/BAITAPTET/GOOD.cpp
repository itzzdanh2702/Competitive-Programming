#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
#define MAXN 1000005
#define ll long long
#define oo 1000000000
#define fi first
#define se second

void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll n, kq = 0;
ll a[MAXN];
map<ll, ll> cnt;

int main()
{
    freopen("GOOD.inp","r",stdin);
    freopen("GOOD.out","w",stdout);
    FAST();
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        cnt[a[i]]++;
    }
    for (auto x : cnt)
    {
        kq = kq + (x.se * (x.se - 1)) / 2;
    }
    cout << kq;
}
