#include <bits/stdc++.h>
using namespace std;
#define ll long long
const long long MOD = 1000000007;
#define MAXN 1000005
#define oo 1000000000
void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll TC;
ll n;
ll a[MAXN];
int main()
{
    cin >> TC;
    while (TC--)
    {
        map<ll, ll> mp;
        ll ma = -1;
        cin >> n;
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i];
            ++mp[a[i]];
        }
        for (auto x : mp)
        {
            ma = max(ma, x.first + x.second - 1);
        }
        cout << ma << '\n';
    }
}