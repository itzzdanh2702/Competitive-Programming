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

int TC;
int a[MAXN];
int b[MAXN];
int n, k;
int pre[MAXN];

int main()
{
    FAST();
    cin >> TC;
    while (TC--)
    {
        memset(pre,0,sizeof(pre));
        int tmp = 1;
        int cnt = 0;
        int ans = 0;
        cin >> n >> k;
        for (int i = 1; i <= n; ++i)
        {
            ++cnt;
            if (cnt < k)
            {
                b[i] = tmp;
            }
            else if (cnt == k)
            {
                b[i] = tmp;
                cnt = 0;
                ++tmp;
            }
        }
        for (int i = 1; i <= n; ++i)
        {
            if (b[i] != b[i - 1])
            {
                if (n - i + 1 > i)
                {
                    pre[i]++;
                    ans += 2;
                }
                else if (n - i + 1 == i)
                    ans += 1;
            }
        }
        cout << ans << '\n';
    }
}