#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define pii pair<ll, ll>
const long long MOD = 1000000007;
#define MAXN 100005
#define oo 1000000000
void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll TC;
ll n, k;
ll a[MAXN];

int main()
{
    FAST();
    cin >> TC;
    while (TC--)
    {
        ll ma = -1;
        ll S = 0;
        cin >> n >> k;
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i];
            S += a[i];
            ma = max(ma, a[i]);
        }
        if ((S % k == 0) and (S / k >= ma))
        {
            cout << "YES" << '\n';
        }
        else 
        {
            cout << "NO" << '\n';
        }
    }
}