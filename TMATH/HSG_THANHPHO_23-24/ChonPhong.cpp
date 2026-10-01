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

int n, k;
int pre[MAXN];
int ans;
string S;

bool check(int mid)
{
    bool ok = false;
    for (int i = 1; i <= n; ++i)
    {
        if (S[i] == '0')
        {
            if (i >= mid + 1)
            {
                if (pre[i - 1] - pre[i - mid - 1] + pre[i + mid] - pre[i] >= k)
                    ok = true;
            }
            else
            {
                if (pre[i - 1] + pre[i + mid] - pre[i] >= k)
                    ok = true;
            }
        }
    }
    if (ok)
        return true;
    return false;
}
int main(int argc, char const *argv[])
{
    FAST();
    // freopen("CHONPHONG.inp", "r", stdin);
    // freopen("CHONPHONG.out", "w", stdout);
    cin >> n >> k;
    cin >> S;
    S = " " + S;
    for (int i = 1; i <= n; ++i)
    {
        pre[i] = pre[i - 1];
        pre[i] += (S[i] == '0');
    }
    int l = 1, r = n;
    while (l <= r)
    {
        int mid = (l + r) / 2;

        if (check(mid))
        {
            r = mid - 1;
            ans = mid;
        }
        else
        {

            l = mid + 1;
        }
    }
    cout << ans;
    return 0;
}
