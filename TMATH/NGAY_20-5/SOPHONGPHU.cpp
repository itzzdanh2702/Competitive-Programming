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
ll cnt = 0;
int a[MAXN];
bool d[MAXN];
bool sum(ll n)
{
    ll S = 1;
    for (int i = 2; i <= sqrt(n); ++i)
    {
        if (n % i == 0)
        {
            int tmp = n / i;
            if (tmp == i)
            {
                S += i;
            }
            else
            {
                S += i + n / i;
            }
            if (S > n)
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    FAST();
    // freopen("PP.inp", "r", stdin);
    // freopen("PP.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        if (d[a[i]])
        {
            ++cnt;
            continue;
        }
        if (sum(a[i]))
        {
            d[a[i]] = 1;
            cout << a[i] << ' ';
        }
    }
    cout << cnt;
}