#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nmax 1000000
ll n, x, q1, q2, q3, S = 0;
int main()
{
    freopen("A.inp", "r", stdin);
    freopen("A.out", "w", stdout);
    cin >> n >> x;
    while (n--)
    {
        cin >> q1 >> q2;

        if (abs(q1 - q2) > x)
        {
            cin >> q3;
            S += q3;
        }
        else
        {
            S += max(q1, q2);
        }
    }
    cout << S;
}
