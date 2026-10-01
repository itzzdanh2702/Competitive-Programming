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
int n, m;
ll k[MAXN];
ll a[MAXN], b[MAXN], c[MAXN];

int main()
{
    FAST();
    cin >> TC;
    while (TC--)
    {
        cin >> n >> m;
        for (int i = 1; i <= n; ++i)
        {
            cin >> k[i];
        }
        sort(k + 1, k + n + 1);
        for (int i = 1; i <= m; ++i)
        {
            cin >> a[i] >> b[i] >> c[i];
        }
        for (int i = 1; i <= m; ++i)
        {   
            int it1 = lower_bound(k + 1, k + n + 1, b[i]) - k;
            if ((it1 <= n) && ((k[it1] - b[i]) * (k[it1] - b[i]) < 4 * a[i] * c[i]))
            {
                cout << "YES" << '\n';
                cout << k[it1] << '\n';
                continue;
            }
            if ((it1 >= 2) && (k[it1 - 1] - b[i]) * (k[it1 - 1] - b[i]) < 4 * a[i] * c[i])
            {
                cout << "YES" << '\n';
                cout << k[it1 - 1] << '\n';
                continue;
            }
            cout << "NO" << '\n';
        }

        cout << '\n';
    }
}