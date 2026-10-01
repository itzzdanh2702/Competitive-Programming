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

int n, TC;
int a[MAXN];
ll d[MAXN];
ll pre[MAXN];
ll pre1[MAXN];

int main()
{
    FAST();
    cin >> n >> TC;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    while (TC--)
    {
        int l, r, k;
        cin >> l >> r >> k;
        pre[r + 1] -= k;
        pre[l] += k;
    }
    for (int i = 1; i <= n; ++i)
    {
        pre1[i] = pre1[i - 1] + pre[i];
        //cout << pre[i] + a[i];
        cout << pre1[i] + a[i] << ' ';
    }
}