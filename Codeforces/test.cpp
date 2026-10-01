#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        vector<int> v;
        v.clear();
        int n;
        cin >> n;
        int ans = 0;
        int mn = n + 1, mnWin = n + 1;
        while (n--)
        {
            int x;
            cin >> x;
            v.push_back(x);
            if (mn < x && x < mnWin)
            {
                ans += 1;
                mnWin = x;
            }
            mn = min(mn, x);
        }
        //cout << ans << '\n';
        if (ans == 4)
        {
            for (auto x : v)
                cout << x << ' ';
            cout << '\n'; 
        }
    }
}

/*
Inp
7
4 7 2 6 5 3 1 
Out
4
*/