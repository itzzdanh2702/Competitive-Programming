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

int n;
int a[MAXN];
int cnt = 0;

int main()
{
    FAST();
    freopen("Hsin.inp", "r", stdin);
    freopen("Hsin.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n - 2; ++i)
    {
        if ((a[i] > a[i + 1]) and (a[i + 1] < a[i + 2]))
        {
            ++cnt;
        }
        else if ((a[i] < a[i + 1]) and (a[i + 1] > a[i + 2]))
        {
            ++cnt;
        }
    }
    cout << cnt;
}