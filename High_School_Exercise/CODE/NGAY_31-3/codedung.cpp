#include <bits/stdc++.h>

using namespace std;

const int mod = 998244353;

void solve()
{
    string s;
    cin >> s;
    int n = s.length();
    if (n == 1)
    {
        cout << 1 << endl;
        return;
    }

    int ans[n] = {0};

    ans[0] = 1;
    ans[1] = 1 + (s[0] != s[1]);
    for (int i = 2; i < n; i++)
    {
        ans[i] = ans[i - 1];
        if (s[i] != s[i - 1])
        {
            ans[i] = (ans[i] + ans[i - 2]) % mod;
        }
    }
    cout << ans[n - 1] << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
