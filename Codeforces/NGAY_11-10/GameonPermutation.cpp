#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define pii pair<ll, ll>
const long long MOD = 1000000007;
#define MAXN 3 * 100005
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

int main()
{
    FAST();
    cin >> TC;
    while (TC--)
    {
        int ans = 0;
        cin >> n;
        for (int i = 1; i <= n; ++i)
            cin >> a[i];
        int tmp = n + 1, mi = n + 1;
        for (int i = 1; i <= n; ++i)
        {
            if ((a[i] < tmp) && (a[i] > mi))
            {
                ++ans;
                tmp = a[i];
            }
            mi = min(mi, a[i]);
        }
        cout << ans << '\n'; 
    }
}