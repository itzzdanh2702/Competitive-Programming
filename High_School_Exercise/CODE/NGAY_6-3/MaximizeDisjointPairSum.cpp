#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
#define ll long long
#define MAXN 1000005
#define oo 1000000000
void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll TC;
ll m, dist;
ll a[MAXN];
bool check[MAXN];
multiset<ll> mu;

int main()
{
    FAST();
    cin >> TC;
    while (TC--)
    {
        memset(check, 0, sizeof(check));
        ll S = 0;
        cin >> m >> dist;
        for (int i = 1; i <= m; ++i)
        {
            cin >> a[i];
        }
        sort(a + 1, a + m + 1);
        for (int i = m; i >= 2; --i)
        {
            if (a[i] - a[i - 1] < dist)
            {
                S += a[i] + a[i - 1];
                i -= 1;
            }
            else
            {
                continue;
            }
        }
        cout << S << '\n';
    }
}