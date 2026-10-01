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
ll ma = -1;
string S;
map<string, ll> mp;
int main()
{
    FAST();
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> S;
        ++mp[S];
    }
    for (auto x : mp)
    {
        ma = max(ma, x.se);
    }
    for(auto x : mp)
    {
        if(x.se == ma)
        {
            cout << x.fi;
        }
    }
}