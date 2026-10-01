#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, dem = 0, ans1, ans2, kq[1005][1005], ma = 0;
long double mi = 1, ans[1005][1005];
string S;
int main()
{
    freopen("B.inp", "r", stdin);
    freopen("B.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> S;
    for (int i = 0; i < n - 1; i++)
    {
        map<char, ll> mp;
        dem = 0;
        if (mp[S[i]] == 0)
            dem++;
        mp[S[i]]++;
        for (int j = i + 1; j < n; j++)
        {
            if (mp[S[j]] == 0)
                dem++;
            mp[S[j]]++;
            ll res = dem;
            ll pos = j - i + 1;
            ans[i][j] = (long double)res / (long double)pos;
            kq[i][j] = pos;
            mi = min(mi, ans[i][j]);
        }
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (ans[i][j] == mi)
            {
                if (ma < kq[i][j])
                {
                    ans1 = i + 1;
                    ans2 = j + 1;
                    ma = kq[i][j];
                }
            }
        }
    }
    cout << ans1 << ' ' << ans2;
    return 0;
}