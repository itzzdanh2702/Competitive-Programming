#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nmax 1000000
ll a[nmax];
ll dp[nmax][3];
ll ans[nmax];
ll n;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    dp[1][1] = dp[1][0]= a[1];
    dp[2][1] = a[2]+a[1];
    dp[2][0] = a[2];
    
    for (int i = 3; i <= n; i++)
    {
        dp[i][0] = a[i]+dp[i-2][1];
        dp[i][1] = a[i]+dp[i-1][0];
    }
    cout << max(dp[n][0], dp[n][1]);
}
