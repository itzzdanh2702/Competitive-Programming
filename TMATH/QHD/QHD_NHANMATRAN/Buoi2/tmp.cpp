#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e5 + 5;
const ll oo = 1e18;

void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll n, q, k;
ll a[MAXN];
ll b[MAXN];
ll S = 0;
ll ans = 0;
bool check = 0;

int main()
{
    freopen("POSITION.inp","r",stdin);
    freopen("POSITION.out","w",stdout);
    FAST();
    cin >> n >> q >> k;
    for (int i = 1; i <= q; ++i)
    {
        cin >> a[i];
        if (a[i] == 1)
            S -= 1;
        else
            S += 1;
    }
    for (int i = 1; i <= k; ++i)
    {
        cin >> b[i];
    }
    if (S < 0)
    {
        S = -S;
    }
    b[0] = 1;
    b[k + 1] = n;
    for (int i = 1; i <= k + 1; ++i)
    {
        b[i - 1] += S;
        if (b[i] <= b[i - 1])
            continue;
        if (i == 1)
        {
            if (b[i] == 1)
                check = 1;
            else
                ans += b[i] - b[i - 1];
            continue;
        }
        ans += b[i] - b[i - 1] - 1;
        if (check)
        {
            check = 0;
            continue;
        }
        if (i == k)
            if (b[i] == n)
                break;
        if (i == k + 1)
            ++ans;
    }
    cout << ans;
}
