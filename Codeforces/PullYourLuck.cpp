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

int TC;
int n, x, p;

void solve()
{
    for (int i = 1; i <= min(2 * n, p); ++i)
    {
        x = (x + i) % n;
        if (x == 0)
        {
            cout << "Yes" << '\n';
            return;
        }
    }
    cout << "No" << '\n';
}
int main()
{
    FAST();
    cin >> TC;
    while (TC--)
    {
        cin >> n >> x >> p;
        solve();
    }
}