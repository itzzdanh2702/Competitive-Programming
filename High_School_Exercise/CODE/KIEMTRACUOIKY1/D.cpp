#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
#define ll long long
#define nmax 1000005
#define oo 1000000000
ll a, b;
ll n, m;
void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
ll dem[nmax];
ll ma = -oo;
int main()
{
    freopen("D.inp", "r", stdin);
    freopen("D.out", "w", stdout);
    FAST();
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> a >> b;
        dem[a]++;
        dem[b + 1]--;
    }
    for (int i = 1; i <= n; i++)
    {
        dem[i] = dem[i - 1] + dem[i];
        ma = max(ma, dem[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        if (dem[i] == ma)
        {
            cout << i;
            return 0;
        }
    }
}
