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
int store[MAXN], store1[MAXN], store2[MAXN];

int main()
{
    FAST();
    cin >> TC;
    while (TC--)
    {
        int cnt = 1;
        int a, b, c;
        cin >> a >> b >> c;
        for (int i = 1; i <= 5; ++i)
        {
            if ((a <= b) && (a <= c))
            {
                ++a;
            }
            else if ((c >= b) && (a > b))
            {
                ++b;
            }
            else if ((a > c) && (b > c))
            {
                ++c;
            }
        }
        cout << a * b * c << '\n';
    }
}

// 2 3 4
// 3 3 4
// 2 4 4
// 2 3 5
// 4 3 4