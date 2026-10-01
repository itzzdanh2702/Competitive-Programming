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
int a, b;
int n, q;
int x[MAXN], y[MAXN];
int pos1[MAXN], pos2[MAXN];
ll pre1[MAXN], pre2[MAXN];

int main(int argc, char const *argv[])
{
    freopen("VUA.inp", "r", stdin);
    freopen("VUA.out", "w", stdout);
    FAST();
    cin >> n >> q;
    for (int i = 1; i <= n; ++i)
    {
        cin >> x[i] >> y[i];
        pos1[i] = x[i] + y[i];
        pos2[i] = x[i] - y[i];
    }
    sort(pos1 + 1, pos1 + n + 1);
    sort(pos2 + 1, pos2 + n + 1);
    for (int i = 1; i <= n; ++i)
    {
        pre1[i] = pre1[i - 1] + pos1[i];
        pre2[i] = pre2[i - 1] + pos2[i];
    }
    while (q--)
    {
        ll ans = 0;
        cin >> a >> b;
        int it = lower_bound(pos1 + 1, pos1 + n + 1, a + b) - pos1;
        --it;
        ans += it * (a + b) - pre1[it];
        ans += pre1[n] - pre1[it] - (n - it) * (a + b);
        int it1 = lower_bound(pos2 + 1, pos2 + n + 1, a - b) - pos2;
        int tmp = --it1;
        ans += (a - b) * tmp - pre2[tmp];
        ans += pre2[n] - pre2[tmp] - (n - tmp) * (a - b);
        cout << ans / 2 << '\n';
    }
    return 0;
}
