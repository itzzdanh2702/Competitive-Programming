#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pli pair<ll, int>
#define pil pair<int, ll>
#define fi first
#define se second
#define dim 3
#define tupi tuple<int, int, int>
#define inf 0x3f3f3f3f

const ll nx = 1e6 + 9;
const ll bx = 1e3 + 9;
const ll mod = 1e9 + 7;

//--------------------------------
int t, n;
ll bit[3][nx], res = 0;
vector<ll> vt;
bool check[nx];
ll m;

void update(int dir, int pos, int val)
{
    int idx = pos;
    while (idx <= n)
    {
        bit[dir][idx] += val;
        idx += (idx & (-idx));
    }
}

void updaterange(int l, int r, int val)
{
    update(0, l, (n - l + 1) * val);
    update(0, r + 1, -(n - r) * val);
    update(1, l, val);
    update(1, r + 1, -val);
}

ll get(int dir, int pos)
{
    int idx = pos, res = 0;
    while (idx)
    {
        res += bit[dir][idx];
        idx -= (idx & (-idx));
    }
    return res;
}

ll prefixsum(int u)
{
    return get(0, u) - get(1, u) * (n - u);
}

ll rangesum(int l, int r)
{
    return prefixsum(r) - prefixsum(l - 1);
}

int bs(int l, int r, ll k, ll now)
{
    int res = -1;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        // cout << l << " " << mid << " " << r << " | " << k << " " << now - ((n - mid) - get(2, n) + get(2, mid)) << " | " << get(2, mid) - get(2, mid-1) << "\n";
        if (k <= (ll)(now - ((n - mid) - get(2, n) + get(2, mid))))
        {
            if (!(get(2, mid) - get(2, mid - 1)))
            {
                // cout << "PASS\n";
                res = mid;
                r = mid - 1;
            }
            else
            {
                // cout << mid - 1 - get(2, mid-1) << "\n";
                if (mid - 1 - get(2, mid) > 0)
                    r = mid - 1;
                else
                    l = mid + 1;
            }
            // r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return res;
}

ll mu(ll a, ll n)
{
    if (!n)
        return 1;
    ll tam = mu(a, n >> 1);
    tam = (tam * tam) % mod;
    if (n & 1)
        tam = (tam * a) % mod;
    return tam;
}

void sub4()
{
    memset(bit, 0, sizeof(bit));
    memset(check, 0, sizeof(check));
    vt.clear();
    res = 0;
    cin >> n >> m;
    ll now = ((ll)(n)-1LL) * (ll)(n) / 2LL;
    for (int i = 1; i < n; i++)
    {
        // cout << "M: " << m << "\n";
        // cout << "NOW: " << now << "\n";
        int tmp = bs(1, n, m, now);
        if (tmp == -1)
        {
            cout << -1 << "\n";
            return;
        }
        vt.emplace_back(tmp);
        // for (auto x : vt) cout << x << " ";
        // cout << "\n";
        now -= ((tmp - 1 - rangesum(tmp, tmp)) + (n - tmp) - get(2, n) + get(2, tmp));
        m -= tmp - 1 - rangesum(tmp, tmp);
        updaterange(tmp, n, 1);
        update(2, tmp, 1);
    }
    for (auto x : vt)
    {
        check[x] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!check[i])
        {
            vt.emplace_back(i);
            break;
        }
    }
    // for (auto x : vt) cout << x << " ";
    // cout << "\n";
    for (int i = 0; i < vt.size(); i++)
    {
        (res += vt[i] * mu(2, i)) %= mod;
    }
    cout << res << "\n";
}

//--------------------------------
int main()
{
    // freopen("Invert.Inp", "r", stdin);
    // freopen("Invert.Out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while (t--)
    {
        sub4();
    }
}
/*
Note:

*/