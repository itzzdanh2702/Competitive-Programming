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
int a, b, c;
void solve(int a, int b, int c)
{
    for (int i = 0; i <= 10000; ++i)
    {
        if (i * a == c)
        {
            cout << "Yes" << '\n';
            return;
        }
        else if (i * a > c)
        {
            cout << "No" << '\n';
            return;
        }
        else
        {
            for (int j = 0; j <= 10000; ++j)
            {
                if (i * a + j * b == c)
                {
                    cout << "Yes" << '\n';
                    return;
                }
                else if (i * a + j * b > c)
                {
                    break;
                }
            }
        }
    }
}
int main()
{
    FAST();
    cin >> TC;
    while (TC--)
    {
        cin >> a >> b >> c;
        solve(a,b,c);
    }
}