#include <bits/stdc++.h>
using namespace std;

#define ll long long

int t;
ll x[4], res = 0, sum = 0;

void solve()
{
    if ((x[1] & 1) != (x[2] & 1) or (x[2] & 1) != (x[3] & 1) or sum % 3 != 0)
    {
        cout << "-1\n";
        return;
    }
    sort(x + 1, x + 4);
    res = (x[3] - x[2]) / 2;
    // bien doi x[1] thanh x[2]
    if (res >= (x[2] - x[1]) / 2)
    {
        res = 0;
        res += (x[2] - x[1]) / 2;
        x[2] -= 2 * res;
        x[3] -= 4 * res;
        res += (x[3] - x[2]) / 3;
    }
    else
    {
        x[2] -= 2 * res;
        x[3] -= 4 * res;
        res += (x[2] - x[1]) / 3;
    }
    cout << res << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while (t--)
    {
        sum = 0;
        for (int i = 1; i <= 3; i++)
        {
            cin >> x[i];
            sum += x[i];
        }
        solve();
    }
}
