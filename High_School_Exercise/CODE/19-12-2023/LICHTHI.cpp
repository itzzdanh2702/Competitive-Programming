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

int n, m;
int a[MAXN], b[MAXN];
int cnt = 0, S = 0;
int pos;
bool check[MAXN];

int main(int argc, char const *argv[])
{
    FAST();
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        if ((check[a[i]] == 0) && (a[i] != 0))
        {
            check[a[i]] = 1;
            ++cnt;
        }
        if (cnt == m)
        {
            pos = i;
            break;
        }
    }
    for (int i = 1; i <= m; ++i)
    {
        cin >> b[i];
        S += b[i];
    }
    for (int i = pos; i <= n; ++i)
    {
        if (m + S <= i)
            return cout << i, 0;
    }
    cout << "-1"; 
    return 0;
}
// 0 1 0 0 2 5 0 1 0 0 2
