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

int m, n;
char a[11][11];
string S[11][11];

int main(int argc, char const *argv[])
{
    FAST();
    cin >> m >> n;
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if ((i - 1 <= m) && (j - 1 <= n))
            {
                S[i][j] = max({S[i][j], S[i - 1][j], S[i][j - 1]}) + a[i][j];
            }
        }
    }
    cout << S[m][n];
    return 0;
}
