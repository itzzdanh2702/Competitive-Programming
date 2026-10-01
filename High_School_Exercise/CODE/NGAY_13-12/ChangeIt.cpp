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
ll N;
ll a[MAXN];
map<ll, ll> dem;
set<ll> s;
int main()
{
    cin >> TC;
    while (TC--)
    {
        ll ans = 0;
        s.clear();
        dem.clear();
        cin >> N;
        for (int i = 1; i <= N; ++i)
        {
            cin >> a[i];
            ++dem[a[i]];
        }
        for (auto x : dem)
        {
            s.insert(x.second);
        }

        for (auto x : s)
        {
            ans = x;
            break;
        }
        if (ans == N)
        {
            cout << 0;
        }
        else
        {
            cout << ans;
        }
        cout << '\n';
    }
}