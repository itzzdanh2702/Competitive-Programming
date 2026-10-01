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

ll n, khanh, thanh;
ll total_khanh, total_thanh;
ll ma = -oo;
int main()
{
    freopen("GAME.inp", "r", stdin);
    freopen("GAME.out", "w", stdout);
    cin >> n;
    while (n--)
    {
        cin >> khanh >> thanh;
        if (khanh > thanh)
        {
            total_khanh += khanh - thanh;
        }
        else
        {
            total_thanh += thanh - khanh;
        }
        ma = max(ma, abs(khanh - thanh));
    }
    if (total_khanh > total_thanh)
        cout << "1" << endl;
    else if (total_thanh > total_khanh)
        cout << "2" << endl;
    cout << ma;
}
