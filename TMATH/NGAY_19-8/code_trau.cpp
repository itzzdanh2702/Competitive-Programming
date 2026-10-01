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
int x, y;

int main(int argc, char const *argv[])
{
    FAST();
    freopen("spiral.inp", "r", stdin);
    freopen("spiral.out", "w", stdout);
    cin >> TC;
    while (TC--)
    {
        cin >> x >> y;
        int tmp = max(x, y);
        if (tmp & 1)
            cout << tmp * tmp - (abs(x - 1) + abs(y - tmp)) << '\n';
        else
            cout << tmp * tmp - (abs(x - tmp) + abs(y - 1)) << '\n';
    }
    return 0;
}
