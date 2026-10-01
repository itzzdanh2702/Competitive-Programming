#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
#define ll long long
#define MAXN 1000005
#define oo 1000000000
void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
ll n, k;
ll ma = -oo;
ll dem = 0;
ll a[MAXN];
map<ll, ll> mp;
int main()
{
    //freopen("MISSNUM.inp", "r", stdin);
    //freopen("MISSNUM.out", "w", stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        mp[a[i]]++;
        ma = max(ma, a[i]);
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= ma; i++)
    {
        if (mp[i] == 0)
        {
            dem++;
            if (dem == k)
                return cout << i, 0;
        }
    }
    cout << n + k;
}