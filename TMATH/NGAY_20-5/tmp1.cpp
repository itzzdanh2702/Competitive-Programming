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

ll n;
ll store[41];
int tmp_pos = 0;
pii pos[41];

int main()
{
    FAST();
    freopen("MOO.INP", "r", stdin);
    freopen("MOO.OUT", "w", stdout);
    cin >> n;
    store[0] = 3;
    pos[0].fi = 1;
    pos[0].se = 3;
    if (n == 1)
    {
        return cout << 'm', 0;
    }
    else if (n == 2)
    {
        return cout << 'o', 0;
    }
    else if (n == 3)
    {
        return cout << 'o', 0;
    }
    for (int i = 1; i <= 40; ++i)
    {
        store[i] = 2 * store[i - 1] + i + 3;
        pos[i].fi = store[i - 1] + 1;
        pos[i].se = store[i - 1] + i + 3;
    }
    for (int i = 1; i <= 40; ++i)
    {
        if (store[i] >= n)
        {
            tmp_pos = i;
            break;
        }
    }
    for (int i = tmp_pos; i >= 0; --i)
    {
        if ((n >= pos[i].fi) && (n <= pos[i].se))
        {
            if (n == pos[i].fi)
                cout << 'm';
            else
                cout << 'o';
        }
        else if (n > pos[i].se)
            n -= pos[i].se;
    }
}
