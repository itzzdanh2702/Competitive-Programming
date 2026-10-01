#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a, b;
ll S;
int main()
{
    freopen("SIMPCAL.inp", "r", stdin);
    freopen("SIMPCAL.out", "w", stdout);
    cin >> a >> b;
    if ((a >= 0) and (b >= 0))
    {
        if (b >= a)
            S = abs(b - a);
        else
        {
            S = a + 1;
        }
    }
    else if ((a <= 0) and (b >= 0))
    {
        ll p = abs(a + b);
        ll q = abs(a - b);
        if (p >= q)
            S = q;
        else if (p < q)
            S = p + 1;
    }
    else if ((a >= 0) and (b <= 0))
    {
        ll p = abs(a + b);
        ll q = abs(a - b);
        if (p <= q)
            S = p + 1;
        else if (p > q)
            S = q;
    }
    else if ((a <= 0) and (b <= 0))
    {
        if (a <= b)
            S = abs(b - a);
        else
        {
            ll p = 2 + abs(a - b);
            ll q = abs(a + b) + 1;
            if (p <= q)
                S = p;
            else
                S = abs(b + a) + 1;
        }
    }
    cout << S;
}