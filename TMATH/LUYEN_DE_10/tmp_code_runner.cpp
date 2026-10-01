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

int n, ma = -oo;
int a[MAXN];
int len1[MAXN], len2[MAXN];
int xuoi[MAXN], nguoc[MAXN];
int ma1[MAXN], ma2[MAXN];

int main()
{
    FAST();
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    len1[1] = len2[1] = oo;
    for (int i = 1; i <= n; ++i)
    {
        int it = lower_bound(len1 + 1, len1 + xuoi[i - 1] + 1, a[i]) - len1;
        len1[it] = a[i];
        xuoi[i] = max(xuoi[i - 1], it);
        ma1[i] = len1[xuoi[i]];
    }
    for (int i = n; i >= 1; --i)
    {
        int it = lower_bound(len2 + 1, len2 + nguoc[i + 1] + 1, a[i]) - len2;
        len2[it] = a[i];
        nguoc[i] = max(nguoc[i + 1], it);
        ma2[i] = len2[nguoc[i]];
    }
    for (int i = 1; i <= n; ++i)
    {
        ma = max(ma, min(xuoi[i], nguoc[i]));
    }
    cout << 2 * ma - 1;
}