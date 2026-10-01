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

ll m, n;
string S, T;
map<char, vector<ll>> mp;
ll mini[MAXN], maxi[MAXN];

int main()
{
    cin >> m >> n;
    cin >> S >> T;
    for (int i = 0; i < m; ++i)
    {
        mp[S[i]].push_back(i);
    }
    ll mi = -1;
    for (int i = 0; i < n; ++i)
    {
        ll it = upper_bound(mp[T[i]].begin(), mp[T[i]].end(), mi) - mp[T[i]].begin();
        ll tmp1 = mp[T[i]][it];
        mini[i] = tmp1;
        mi = tmp1;
    }
    for (auto &x : mp)
    {
        for (auto &y : x.second)
        {
            y = -y;
        }
        sort(x.second.begin(), x.second.end());
    }
    ll ma = -1e9;
    for (int i = n - 1; i >= 0; --i)
    {
        ll it = upper_bound(mp[T[i]].begin(), mp[T[i]].end(), ma) - mp[T[i]].begin();
        ll tmp2 = mp[T[i]][it];
        maxi[i] = -tmp2;
        ma = tmp2;
    }
    ll tmp = -1;
    for (int i = 1; i < T.size(); ++i)
    {
        tmp = max(tmp, maxi[i] - mini[i - 1]);
    }
    cout << tmp;
}
