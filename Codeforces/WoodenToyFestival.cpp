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
int n;
int a[MAXN];

bool check(int k)
{
    int pos1 = 0, pos2 = 0;
    int l = 0, r = 1e9;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (mid - k <= a[1])
        {
            pos1 = mid;
            l = mid + 1;
        }
        else if (mid - k > a[1])
        {
            r = mid - 1;
        }
    }
    ++pos1;
    int l1 = 0, r1 = 1e9;
    while (l1 <= r1)
    {
        int mid1 = (l1 + r1) / 2;
        if (mid1 + k >= a[n])
        {
            pos2 = mid1;
            r1 = mid1 - 1;
        }
        else
        {
            l1 = mid1 + 1;
        }
    }
    --pos2;
    if (pos2 <= pos1)
        return true;
    int it = upper_bound(a + 1, a + n + 1, pos1 + k - 1) - a;
    int pos4 = 0;
    for (int i = n; i >= 1; --i)
    {
        if (a[i] < pos2 + 1 - k)
        {
            pos4 = i;
            break;
        }
    }
    if (a[it] + 2 * k >= a[pos4])
        return true;
    return false;
}
int main()
{
    FAST();
    cin >> TC;
    while (TC--)
    {
        int ans = 0;
        cin >> n;
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i];
        }
        sort(a + 1, a + n + 1);
        int l = 0, r = oo;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (check(mid))
            {
                ans = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        cout << ans << '\n';
    }
}