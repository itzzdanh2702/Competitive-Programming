/// Author : manhlinh.a2k51.pbc
/// ..-. .- .-.. .-.. / .. -. / .-.. --- ...- . / .-- .. - .... / .- -. -.- .... .- -. ....
#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
#define MAXN 1000005
#define oo 1000000000
#define rs(x, a) memset(x, (a), sizeof x)
#define BIT(mask, i) (((mask) >> (i)) & 1)
#define FILE(X)                     \
    freopen(#X ".INP", "r", stdin); \
    freopen(#X ".OUT", "w", stdout);

void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int TC;
int n;
int a[MAXN];
int cnt[10];

int main()
{
    FAST();
    cin >> TC;
    while (TC--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        sort(a + 1, a + n + 1);
        int ans = oo;
        for (int j = max(0, a[1] - 5); j <= a[1]; j++)
        {
            for (int i = 1; i <= n; i++)
            {
                int k = a[i] - j;
                cnt[5] += k / 5;
                k %= 5;
                cnt[2] += k / 2;
                k %= 2;
                if (k)
                    cnt[k]++;
            }
            cout << j << ' ' << cnt[1] + cnt[2] + cnt[5] << '\n';
            //ans = min(ans, cnt[1] + cnt[2] + cnt[5]);
            cnt[1] = cnt[2] = cnt[5] = 0;
        }
        cout << ans << "\n";
        cnt[1] = cnt[2] = cnt[5] = 0;
    }
}