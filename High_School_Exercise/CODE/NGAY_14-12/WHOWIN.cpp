#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nmax 1001
ll n;
ll dp[nmax][nmax];
ll a[nmax];
ll S;
int main()
{
    freopen("WHOWIN.inp", "r", stdin);
    freopen("WHOWIN.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        S += a[i];
    }
    for (int i = 1; i <= n; i++)
        dp[i][i] = a[i];
    for (int i = n; i >= 1; i--)
    {
        for (int j = i + 1; j <= n; j++)
        {
            dp[i][j] = max({a[i] - dp[i + 1][j], a[j] - dp[i][j - 1]});
        }
    }
    if (dp[1][n] > 0)
    {
        cout << "1" << ' ';
        cout << (S + dp[1][n]) / 2;
    }
    else
    {
        cout << "0" << ' ';
        cout << (S - dp[1][n]) / 2;
    }
}