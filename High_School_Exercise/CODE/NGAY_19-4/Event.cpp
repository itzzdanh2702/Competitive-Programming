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

ll st, en;
ll TC;
int main()
{
    map<string, ll> mp;
    mp["monday"] = 2;
    mp["tuesday"] = 3;
    mp["wednesday"] = 4;
    mp["thursday"] = 5;
    mp["friday"] = 6;
    mp["saturday"] = 7;
    mp["sunday"] = 8;
    FAST();
    cin >> TC;
    while (TC--)
    {
        string P, Q;
        ll ans = 0;
        ll dem = 0;
        ll t = 0;
        cin >> P >> Q >> st >> en;
        if (mp[Q] >= mp[P])
        {
            ans = mp[Q] - mp[P] + 1;
        }
        else
        {
            ans = 8 + mp[Q] - mp[P];
        }
        for (int i = ans; i <= en; i += 7)
        {
            if (i >= st)
            {
                ++dem;
                t = i;
            }
        }
        if (dem == 1)
        {
            cout << t << '\n';
        }
        else if (dem > 1)
        {
            cout << "many" << '\n';
        }
        else if (dem == 0)
        {
            cout << "impossible" << '\n';
        }
    }
}