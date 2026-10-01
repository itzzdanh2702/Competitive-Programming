#include <bits/stdc++.h>
using namespace std;
#define ll long long
const long long MOD = 1000000007;
#define MAXN 100005
#define oo 1000000000
#define fi first
#define se second

void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int TC;
int n;
int a[MAXN];
map<int, int> mp;
int mp2[MAXN];
int mp1[MAXN];

int main()
{
    FAST();
    cin >> TC;
    while (TC--)
    {
        int ans = 0;
        memset(mp1, 0, sizeof(mp2));
        memset(mp2, 0, sizeof(mp2));
        mp.clear();
        bool check = 1;
        cin >> n;
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i];
            ++mp[a[i]];
        }
        for (auto x : mp)
        {
            if (x.se % x.fi != 0)
            {
                check = 0;
                break;
            }
        }
        if (check == 0)
        {
            cout << "-1" << '\n';
            continue;
        }
        else
        {
            ll dem = 0;
            for (int i = 1; i <= n; ++i)
            {
                if (a[i] == 1)
                {
                    ++dem;
                    cout << dem << ' ';
                }
                else if (++mp1[a[i]] % a[i] == 1)
                {
                    ++dem;
                    mp2[a[i]] = dem;
                    cout << dem << ' ';
                }
                else
                {
                    ans = mp2[a[i]];
                    cout << ans << ' ';
                }
            }
            cout << "\n";
        }
    }
}