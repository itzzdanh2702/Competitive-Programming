#include <bits/stdc++.h>
using namespace std;
#define ll long long
const long long MOD = 1000000007;
#define MAXN 3 * 100005
#define oo 100000000
void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

string a;
int TC;
int n, k;
int pre_dif[MAXN];

int main()
{
    FAST();
    cin >> TC;
    while (TC--)
    {
        int tmp = 0;
        int ans = 0, kq = oo;
        cin >> n >> k;
        cin >> a;
        a = " " + a;
        for (int i = 2; i <= n; ++i)
        {
            pre_dif[i] = pre_dif[i - 1];
            if (a[i] != a[i - 1])
            {
                pre_dif[i] = pre_dif[i - 1] + 1;
            }
        }
        for (int i = k; i <= n; ++i)
        {
            ans = 0;
            if (a[i] == '0')
            {
                ans += pre_dif[i] - pre_dif[i - k + 1] + 1;
            }
            else
            {
                ans += pre_dif[i] - pre_dif[i - k + 1];
            }
            kq = min(ans, kq);
        }
        cout << kq << '\n';
    }
}