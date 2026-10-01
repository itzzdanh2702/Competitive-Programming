#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nmax 1000000
ll S, s[nmax], a[nmax], n, p[nmax], P, ans, ans1;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        S += a[i];
    }
    for (int i = 1; i <= n; i++)
        s[i] = s[i - 1] + a[i];
    ll dem = 0;
    for (ll i = 1; i <= n; i++)
    {
        if (S - s[i] == 2 * s[i])
        {
            ans = i;
            dem++;
            break;
        }
    }
    if (dem == 0)
        cout << "-1";
    else if (dem != 0)
    {
        ll dem1 = 0;
        for (ll i = ans + 1; i <= n; i++)
        {
            P += a[i];
            p[i] = p[i - 1] + a[i];
        }
        for (ll i = ans + 1; i <= n; i++)
        {
            if (P - p[i] == p[i])
            {
                dem1++;
                ans1 = i;
                break;
            }
        }
        if (dem1 == 0)
            cout << "-1";
        else
            cout << ans << " " << ans1;
    }
}
