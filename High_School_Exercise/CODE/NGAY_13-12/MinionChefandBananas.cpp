#include<bits/stdc++.h>
#define ll long long

using namespace std;

const ll MAXN = 1e5 + 5;

ll t, n, h, a[MAXN];

bool check(int x)
{
    ll ans = 0;
    for (int i = 1 ; i <= n ; i++)
    {
        if (a[i] % x == 0)
            ans += a[i] / x;
        else ans += a[i] / x + 1;
    }
    return ans <= h;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--)
    {
        ll ma;
        cin >> n >> h;
        for (int i = 1 ; i <= n ; i++)
        {
            cin >> a[i];
            ma = max(ma, a[i]);
        }
        ll l = 1, r = ma, mid;
        while (l < r)
        {
            mid = (l + r) / 2;
            if (check(mid))
                r = mid;
            else l = mid + 1;
        }
        cout << l << '\n';
    }
    return 0;
}
