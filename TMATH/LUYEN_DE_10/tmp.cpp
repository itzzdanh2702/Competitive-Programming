#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll nmax = 1e6 + 5;

ll n, a[nmax], incr[nmax], decr[nmax];
vector<ll> vi;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
    {
        auto it = lower_bound(vi.begin(), vi.end(), a[i]);
        if (it == vi.end())
            vi.push_back(a[i]);
        else
            *it = a[i];
        incr[i] = vi.size();
    }
    vi.clear();
    for (int i = n; i >= 1; i--)
    {
        auto it = lower_bound(vi.begin(), vi.end(), a[i]);
        if (it == vi.end())
            vi.push_back(a[i]);
        else
            *it = a[i];
        decr[i] = vi.size();
    }
    cout << incr[2] << ' ';
    ll ans = 0;
    for (int i = 1; i <= n; ++i)
        ans = max(ans, min(incr[i], decr[i]));
    cout << 2 * ans - 1;
    return 0;
}