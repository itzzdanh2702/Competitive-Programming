#include <bits/stdc++.h>
using namespace std;
#define ll long long
const long long MOD = 1000000007;
#define MAXN 1000005
#define oo 1000000000
#define fi first
#define se second

void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll n;
ll a[MAXN];
map<ll, ll> mp;
set<ll, greater<ll>> ans;
int main()
{
    FAST();
    freopen("CARD.inp","r",stdin);
    freopen("CARD.out","w",stdout);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        mp[a[i]]++;
    }
    for (auto x : mp)
    {
        if (x.se % 2 == 1)
        {
            ans.insert(x.fi);
        }
    }
    for (auto x : ans)
    {
        cout << x << ' ';
    }
}
