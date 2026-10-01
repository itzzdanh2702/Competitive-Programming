#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define pii pair<ll, ll>
const long long MOD = 1000000007;
#define MAXN 1000005
const ll nmax = 1e5 + 1;
#define oo 1000000000
void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int TC, p;
int n, k;
vector<int> v;
bool check[nmax];

void sang()
{
    memset(check, true, sizeof(check));
    for (ll i = 2; i * i <= 1e5; i++)
    {
        if (check[i])
        {
            for (ll j = i * i; j <= 1e5; j += i)
            {
                check[j] = false;
            }
        }
    }
}
int legendere(int n, int k)
{
    int dem = 0;
    while (n > 0)
    {
        dem += n / k;
        n /= k;
    }
    return dem;
}

ll POW(int a, int b, int p)
{
    ll ans = 1;
    for (int i = 1; i <= b; ++i)
    {
        ans *= a;
        ans %= p;
    }
    return ans;
}
int main()
{
    FAST();
    sang();
    cin >> TC >> p;
    for (int i = 2; i <= nmax - 1; ++i)
    {
        if (check[i])
        {
            v.push_back(i);
        }
    }
    while (TC--)
    {
        ll ans = 1;
        cin >> n >> k;
        if (n < k)
        {
            cout << 0 << '\n';
            continue;
        }
        int tmp4 = n;
        for (auto x : v)
        {
            if (x > n)
            {
                break;
            }
            int tmp1 = legendere(n, x);
            // cout << tmp1;
            n = tmp4;
            int tmp2 = legendere(n - k, x);
            n = tmp4;
            int tmp3 = legendere(k, x);
            ans *= POW(x, tmp1 - (tmp2 + tmp3), p);
            ans %= p;
            // break;
        }
        cout << ans << '\n';
    }
}