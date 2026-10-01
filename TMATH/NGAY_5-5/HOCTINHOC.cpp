#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define pii pair<ll, ll>
const long long MOD = 1000000007;
#define MAXN 105
#define oo 1000000000
void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int n, m;
int a[MAXN];
int dem = 0;
int sum = 0;
int main()
{
    FAST();
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    if (m == 1)
    {
        cout << "0";
        return 0;
    }
    sort(a + 1, a + n + 1, greater<ll>());
    for (int i = 1; i <= n; ++i)
    {
        sum += a[i];
        if (sum - i >= m)
        {
            return cout << i, 0;
        }
    }
    cout << "-1";
}