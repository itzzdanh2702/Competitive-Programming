#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define pii pair<ll, ll>
const long long MOD = 1000000007;
#define MAXN 10000
#define oo 1000000000
void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int n, m, rem;
int a[71][71];
vector<int> st[71][71];

int main(int argc, char const *argv[])
{
    FAST();
    cin >> n >> m >> rem;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; i <= m; ++j)
        {
            cin >> a[i][j];
            st[i][j].emplace_back(a[i][j]);
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; i <= m; ++j)
        {
            for (auto x : st[i][j])
                cout << x << ' ';
        }
        cout << '\n';
    }
    return 0;
}
