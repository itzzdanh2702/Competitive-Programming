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

int n, x;
int a[MAXN];
map<int, int> d;
int dem = 0;

int main()
{
    cin >> n >> x;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        dem += d[x - a[i]];
        if (x == 2 * a[i])
        {
            ++dem;
        }
        ++d[a[i]];
    }
    cout << dem;
}