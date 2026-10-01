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

int TC;
int n, k;
ll h[MAXN], p[MAXN];
ll pre_sum = 0;
pair<ll, ll> store[MAXN];
bool check = 0;
bool cmp(pair<ll, ll> x, pair<ll, ll> y)
{
    if (x.se != y.se)
        return x.se < y.se;
    return x.fi < y.fi;
}
ll sum(ll k)
{
    return (k * (k + 1)) / 2;
}
int main()
{
    FAST();
    cin >> TC;
    while (TC--)
    {
        check = 0;
        pre_sum = 0;
        cin >> n >> k;
        for (int i = 1; i <= n; ++i)
        {
            cin >> h[i];
            store[i].fi = h[i];
        }
        for (int i = 1; i <= n; ++i)
        {
            cin >> p[i];
            store[i].se = p[i];
        }
        sort(store + 1, store + n + 1, cmp);
        int it = 1;
        for (int i = 1; i <= n; ++i)
        {
            store[i].fi -= k;
        }
        ll tmp = 0;
        for (int i = 1; i <= n; ++i)
        {
            tmp = 0;
            store[i].fi -= pre_sum;
            if (store[i].fi > 0)
            {
                int j = 1;
                while (j <= 100000)
                {
                    if (store[i].fi - 1LL * j * k + 1LL * sum(j) * store[i].se <= 0)
                    {
                        tmp = j;
                        break;
                    }
                    else
                        ++j;
                }
                if (tmp == 0)
                {
                    cout << "NO" << '\n';
                    check = 1;
                    break;
                }
                pre_sum += tmp * k - sum(tmp) * store[i].se;
                k -= tmp * store[i].se;
            }
        }
        if (check)
            continue;
        if (k >= 0)
        {
            cout << "YES" << '\n';
        }
        else
        {
            cout << "NO" << '\n';
        }
    }
}
