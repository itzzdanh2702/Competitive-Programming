#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pii pair<int, int>
#define pil pair<ll, ll>
#define fi first
#define se second

const ll MAXN = 1e5 + 5;

int n;
ll sum[MAXN];
pil a[MAXN];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].fi >> a[i].se;
    }
    for (int i = n; i >= 1; i--)
    {
        sum[i] = sum[i + 1];
        ll tmp = a[i].fi + sum[i];
        if (tmp % a[i].se != 0)
            sum[i] += a[i].se - tmp % a[i].se;
    }
    cout << sum[1];
}