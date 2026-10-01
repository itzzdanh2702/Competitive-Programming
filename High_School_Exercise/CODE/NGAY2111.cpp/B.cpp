#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nmax 1000000
#define ld long double
#define fi first 
#define se second 
ll n, S = 0, tmp;
pair<ld, ld> x, kq;
ll a[nmax];

int main()
{
     freopen("B.inp", "r", stdin);
     freopen("B.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        S += a[i];
    }
    sort(a + 1, a + n + 1, greater<ll>());
    for (int i = 1; i <= n; i++)
    {
        tmp += a[i];
        x = {(ld)i / n * 100, (ld)tmp / S * 100};
        if (x.second - x.first > kq.second - kq.first)
        {
            kq.first = x.first;
            kq.second = x.second;
        }
    }
    cout << setprecision(3) << fixed << kq.first << ' ';
    cout << setprecision(3) << fixed << kq.second;
}