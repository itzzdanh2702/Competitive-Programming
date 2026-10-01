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

int TC;
int a[MAXN];
int ans[MAXN];

int main()
{
    FAST();
    cin >> TC;
    while (TC--)
    {
        int mi = oo;
        int n;
        cin >> n;
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i];
        }
        sort(a + 1, a + n + 1);
        for (int i = 2; i <= n - 1; ++i)
        {
            int l = i - 1, r = i + 1;
            while ((l >= 1) and (r <= n))
            {
                mi = min(mi, abs(a[l] - 2 * a[i] + a[r]));
                if (a[l] - 2 * a[i] + a[r] > 0)
                {
                    --l;
                }
                else
                {
                    // arr[i] - arr[l] - arr[r] + arr[i] < 0;
                    // arr[l] - 2 * arr[i] + arr[t] > 0
                    ++r;
                }
            }
        }
        cout << mi << '\n';
    }
}
// 0 1 6 8