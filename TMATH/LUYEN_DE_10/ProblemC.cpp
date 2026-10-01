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
ll n, k;

int main()
{
    FAST();
    cin >> TC;
    while (TC--)
    {
        cin >> n >> k;
        int tmp = 0, cnt = 0, ans;
        if (k == 0)
        {
            cout << 0 << '\n';
            continue;
        }
        while (tmp < k)
        {
            tmp += n;
            ++cnt;
            if (tmp == n)
            {
                if (tmp >= k)
                {
                    ans = cnt;
                    break;
                }
            }
            else
            {
                if (tmp >= k)
                {
                    ans = cnt;
                    break;
                }
                ++cnt;
                tmp += n;
                if (tmp >= k)
                {
                    ans = cnt;
                    break;
                }
            }
            --n;
        }
        cout << ans << '\n';
    }
}