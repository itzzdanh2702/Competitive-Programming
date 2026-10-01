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

ll TC;

int main()
{
    cin >> TC;
    while (TC--)
    {
        ll dem = 0;
        ll n;
        cin >> n;
        while (n > 0)
        {
            ll tmp1 = 1;
            while (tmp1 <= n)
            {
                tmp1 *= 2;
            }
            n = n - tmp1 / 2;
            ++dem;
        }
        cout << dem - 1 << '\n';
    }
}