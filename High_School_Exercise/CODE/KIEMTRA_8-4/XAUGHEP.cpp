#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int nmax = 1e5 + 1;

string n;
int dem, ans[nmax][30];
set <ll> s;

int main()
{
    freopen("xaughep.inp", "r", stdin);
    freopen("xaughep.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    int m = n.size();
    n = ' ' + n;
    for (int i = 1 ; i < n.size() ; i++)
    {
        for (int j = 0 ; j <= 25 ; j++)
            ans[i][j] += ans[i - 1][j] + 1;
        ans[i][n[i] - 'a']++;
        if (n[i] == n[1])
            dem++;
    }
    if (dem == m)
    {
        cout << n[1];
        return 0;
    }
    for (int i = 2 ; i <= m / 2 ; i++)
    {
        if (m % i == 0)
            s.insert(i);
    }
    for (auto i : s)
    {
        if ((n.size() - 1) % i == 0)
        {
            int pos = m / i;
            bool check = true;
            for (int j = 2 ; j <= pos ; j++)
            {
                for (int x = 0 ; x <= 25 ; x++)
                {
                    if (ans[i * j][x] - ans[i * (j - 1)][x] != ans[i][x])
                    {
                        check = false;
                        break;
                    }
                }
                if (!check)
                    break;
            }
            if (check)
            {
                for (int j = 1 ; j <= i ; j++)
                    cout << n[j];
                return 0;
            }
        }
    }
    cout << -1;
    return 0;
}