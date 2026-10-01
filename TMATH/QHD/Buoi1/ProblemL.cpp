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
int n;
int a[MAXN];

int main(int argc, char const *argv[])
{
    FAST();
    cin >> TC;
    while (TC--)
    {
        ll ans = 0;
        int mi = oo;
        cin >> n;
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i];
            mi = min(mi, a[i]);
        }
        for (int i = 1; i <= n; ++i)
        {
            int tmp = a[i] - mi;
            ans += tmp / 5;
            tmp %= 5;
            ans += tmp / 2;
            tmp %= 2;
            ans += tmp;
        }
        cout << ans << '\n';
    }
    return 0;
}
