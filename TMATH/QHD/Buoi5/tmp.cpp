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

int n, m, k;
int cnt = 0, cnt1 = 0;
int TC;
int tmp, tmp1;
int a[1005][1005];
int pos[2 * MAXN], pos1[2 * MAXN];
int X1, Y1;
bool check = 0;
vector<int> v;
pair<int, int> p[2 * MAXN];

int main()
{
    FAST();
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            cin >> a[i][j];
            v.push_back(a[i][j]);
        }
    }
    sort(v.begin(), v.end());
    tmp = v[v.size() / 2];
    tmp1 = v[v.size() / 2 - 1];

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if ((abs(a[i][j] - tmp)) % k != 0)
            {
                check = 1;
            }
            else
            {
                cnt += abs(a[i][j] - tmp) / k;
            }
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if ((abs(a[i][j] - tmp1)) % k != 0)
            {
                if (check)
                {
                    cout << "-1";
                    return 0;
                }
                else
                {
                    cout << cnt;
                    return 0;
                }
            }
            else
            {
                cnt1 += abs(a[i][j] - tmp1) / k;
            }
        }
    }
    cout << min(cnt, cnt1);
}