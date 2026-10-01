#include <bits/stdc++.h>
using namespace std;
#define ll long long
const long long MOD = 1000000007;
#define MAXN 100005
#define oo 1000000000
void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll TC;
ll m, n;
ll l[MAXN], r[MAXN];
ll t[MAXN];

int main()
{
    FAST();
    cin >> TC;
    while (TC--)
    {
        ll ma = -oo;
        cin >> m >> n;
        for (int i = 1; i <= m; ++i)
        {
            cin >> l[i] >> r[i];
            ma = max(ma, r[i]);
        }
        sort(l + 1, l + m + 1);
        sort(r + 1, r + m + 1);
        for (int i = 1; i <= n; ++i)
        {
            cin >> t[i];
            int it = upper_bound(l + 1, l + m + 1, t[i]) - l;
            --it;
            if ((l[it] <= t[i]) and (t[i] < r[it]))
            {
                cout << 0 << '\n';
            }
            else if (it == n)
            {
                cout << -1 << '\n';
            }
            else
            {
                cout << l[++it] - t[i] << '\n';
            }
        }


    }
}
