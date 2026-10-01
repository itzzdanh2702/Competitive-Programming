#include <bits/stdc++.h>

using namespace std;

long long dp[3001][3001];

int main() {
    
    int n;
    cin >> n;

    vector<int> a(n);
    for (int& x : a) cin >> x;

    for (int i = 0; i < n; ++i) dp[i][i] = a[i];

    for (int i = n - 1; i >= 0; i--)
        for (int j = i + 1; j < n; ++j)
            {
                dp[i][j] = max(a[i] - dp[i + 1][j], a[j] - dp[i][j - 1]);
                cout<<a[i]<<' ';
                cout<< dp[i + 1][j]<<' ';
                cout<<a[j]<<' ';
                cout<< dp[i][j - 1]<<endl;
            }
    cout << dp[0][n - 1] << '\n';
}
