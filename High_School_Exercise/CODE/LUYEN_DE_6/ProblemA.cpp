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

int n;
int dp1[MAXN], dp2[MAXN];
char S[MAXN];

int main()
{
    FAST();
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> S[i];
    }
    for (int i = 2; i <= n; ++i)
        dp1[i] = dp2[i] = oo;
    for (int i = 1; i <= n; ++i)
    {
        if (i == 1)
        {
            if (S[i] == 'A')
            {
                dp1[i] = 0;
                dp2[i] = 1;
            }
            else
            {
                dp1[i] = 1;
                dp2[i] = 0;
            }
        }
        else
        {
            if (S[i] == 'A')
            {
                dp1[i] = min(dp2[i - 1] + 1, dp1[i - 1]);
                dp2[i] = min(dp1[i - 1],dp2[i - 1]) + 1;
            }
            else
            {
                dp1[i] = min(dp1[i - 1],dp2[i - 1]) + 1;
                dp2[i] = min(dp1[i - 1] + 1, dp2[i - 1]);
            }
        }
    }
    cout << dp1[n];
}