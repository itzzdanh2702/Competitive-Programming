#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    freopen("HCN.inp", "r", stdin);
    freopen("HCN.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    ll x1, y1, x2, y2, x3, y3, ans1, ans2;
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    cin >> x3 >> y3;
    ans1 = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    ans2 = (x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3);
    for (ll i = 1; i <= 1000; i++)
    {
        for (ll j = 1; j <= 1000; j++)
        {
            if ((i - x3) * (i - x3) + (j - y3) * (j - y3) == ans1 && (i - x2) * (i - x2) + (j - y2) * (j - y2) == ans2)
            {
                if ((i != x1 || j != y1) && (i != x2 || j != y2) && (i != x3 || j != y3))
                {
                    cout << i << ' ' << j;
                    return 0;
                }
            }
        }
    }
    return 0;
}