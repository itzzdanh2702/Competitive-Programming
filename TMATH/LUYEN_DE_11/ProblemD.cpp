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

int n, d, r;
int a[MAXN], b[MAXN];

int main()
{
    FAST();
    while (cin >> n >> d >> r)
    {
        if ((n == d) && (d == r) && (d == 0))
            break;
        bool check = 0;
        int cnt = 0, pos;
        ll S = 0, ans = 0;
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i];
        }
        for (int i = 1; i <= n; ++i)
        {
            cin >> b[i];
        }
        sort(a + 1, a + n + 1);
        sort(b + 1, b + n + 1);
        for (int i = 1; i <= n; ++i)
        {
            S += a[i];
            if (check)
            {
                ans += a[i] * r;
                continue;
            }
            if (S >= d)
            {
                ++cnt;
                ans += (S - d) * r;
                S = ;
                if (cnt == n)
                {
                    check = 1;
                }
            }
        }
        for (int i = 1; i <= n; ++i)
        {
            S += b[i];
            if (check)
            {
                ans += b[i] * r;
                continue;
            }
            if (S >= d)
            {
                ++cnt;
                ans += (S - d) * r;
                S = 0;
                if (cnt == n)
                {
                    check = 1;
                }
            }
        }
        cout << ans << '\n';
    }
}