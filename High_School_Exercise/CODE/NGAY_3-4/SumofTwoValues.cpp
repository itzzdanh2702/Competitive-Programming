#include <bits/stdc++.h>
using namespace std;
#define ll long long
const long long MOD = 1000000007;
#define MAXN 2 * 100005
#define oo 1000000000
void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll n, k;
ll a[MAXN];
map<ll,ll> d;

int main()
{
    FAST();
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    ll tmp2 = 0, val;
    for (int i = 1; i <= n; ++i)
    {
        if (d[k - a[i]] >= 1)
        {
            tmp2 = i;
            val = k - a[i];
            break;
        }
        ++d[a[i]];
    }
    if (tmp2 == 0)
    {
        cout << "IMPOSSIBLE";
        return 0;
    }
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] == val)
        {
            cout << i << ' ' << tmp2;
            return 0;
        }
    }
}