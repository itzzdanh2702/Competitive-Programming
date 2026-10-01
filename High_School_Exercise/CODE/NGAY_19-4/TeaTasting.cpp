#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define pii pair<ll, ll>
const long long MOD = 1000000007;
#define MAXN 2 * 100005
#define oo 1000000000
void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int TC;
int n;
ll a[MAXN], b[MAXN];
ll pre[MAXN];
ll pre1[MAXN];
ll cnt[MAXN];
ll kq[MAXN];
int main()
{
    FAST();
    cin >> TC;
    while (TC--)
    {
        cin >> n;
        for (int i = 1; i <= n + 1; ++i)
        {
            pre[i] = kq[i] = pre1[i] = cnt[i] = 0;
        }
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i];
        }
        for (int i = 1; i <= n; ++i)
        {
            cin >> b[i];
            pre[i] = pre[i - 1] + b[i];
        }
        for (int i = 1; i <= n; ++i)
        {
            int tmp = upper_bound(pre + 1, pre + n + 1, a[i] + pre[i - 1]) - pre - 1;
            cnt[i]++;
            cnt[tmp + 1]--;
            kq[tmp + 1] += a[i] - (pre[tmp] - pre[i - 1]);
        }
        for (int i = 1; i <= n; ++i)
        {
            cnt[i] += cnt[i - 1];
        }
      
        for (int i = 1; i <= n; ++i)
        {
            cout << kq[i] + cnt[i] * b[i] << ' ';
        }
        cout << '\n';
    }
}