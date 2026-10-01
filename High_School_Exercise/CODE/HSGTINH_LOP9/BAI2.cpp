#include <bits/stdc++.h>
using namespace std;
#define ll long long
const long long MOD = 1000000007;
#define MAXN 1000005
#define oo 1000000000
void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll n, t;
bool check[MAXN];
ll cnt = 0;
int main()
{
    freopen("HANGCAY.INP", "r", stdin);
    freopen("HANGCAY.OUT", "w", stdout);
    FAST();
    memset(check, false, sizeof(check));
    cin >> n >> t;
    while (t--)
    {
        ll a, b;
        cin >> a >> b;
        for (int i = a; i <= a + b; ++i)
        {
            if (i > n)
                break;
            if (!check[i])
            {
                ++cnt;
                check[i] = true;
                // cout << i << ' ';
            }
        }
        for (int i = a; i >= a - b; --i)
        {
            if (i < 1)
                break;
            if (!check[i])
            {
                ++cnt;
                check[i] = true;
            }
        }
    }
    cout << cnt;
}