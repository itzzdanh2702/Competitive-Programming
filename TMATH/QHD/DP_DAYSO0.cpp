#include <bits/stdc++.h>
using namespace std;
#define ll long long
const long long MOD = 1000000007;
#define MAXN 1000005
#define oo 1000000000
void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll n;
ll a[MAXN];
ll pre_min[MAXN];
ll ma = 0;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    pre_min[0] = oo;
    for (int i = 1; i <= n; ++i)
    {
        pre_min[i] = min(pre_min[i - 1], a[i]);
    }
    for (int i = 1; i <= n; ++i)
    {
        ma = max(ma, a[i] - pre_min[i]);
    }
    cout << ma;
}