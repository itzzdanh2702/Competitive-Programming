#include <bits/stdc++.h>
using namespace std;
#define ll long long
const long long MOD = 1000000007;
#define MAXN 1000005
void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int TC;
int b[MAXN];
ll n, m;
ll store[MAXN];
ll sum[MAXN];
bool check1[MAXN];
void solve()
{
    ll kq = 0;
    ll S;
    ll tmp;
    int pos1;
    if (n * (n - 1) / 2 < m)
    {
        cout << "-1" << '\n';
        return;
    }
    if (m == 0)
        for (int i = 1; i <= n; ++i)
            b[i] = i;
    else if (m == 1)
    {
        for (int i = 1; i <= n - 2; ++i)
            b[i] = i;
        b[n - 1] = n;
        b[n] = n - 1;
    }
    else
    {
        for (int i = 1; i <= n - 1; ++i)
            sum[i] = sum[i - 1] + i;
        sort(sum + 1, sum + n, greater<ll>());
        for (int i = 1; i <= n - 1; ++i)
            if (sum[i] < m)
            {
                pos1 = i - 1;
                S = sum[i];
                break;
            }
        for (int i = 1; i <= n; ++i)
            check1[i] = 0;
        b[pos1] = pos1 + m - S;
        check1[b[pos1]] = 1;
        b[n] = pos1;
        check1[b[n]] = 1;
        for (int i = 1; i < pos1; ++i)
        {
            b[i] = i;
            check1[b[i]] = 1;
        }
        int tmp2 = n;
        int i = pos1 + 1;
        while (i <= n - 1)
            if (check1[tmp2] == 0)
            {
                b[i] = tmp2;
                ++i;
                --tmp2;
            }
            else
                --tmp2;
    }
    int tmp3 = 1;
    for (int i = 0; i <= n - 1; ++i)
    {
        kq += b[tmp3] * store[i];
        kq %= MOD;
        ++tmp3;
    }
    cout << kq << '\n';
}

int main()
{
    freopen("Invert.Inp", "r", stdin);
    freopen("Invert.Out", "w", stdout);
    FAST();
    cin >> TC;
    store[0] = 1;
    for (int i = 1; i <= 1e6; ++i)
        store[i] = (store[i - 1] * 2LL) % MOD;
    while (TC--)
    {
        cin >> n >> m;
        solve();
    }
}