#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second

using namespace std;

const ll mod = 1e9 + 7;
const int nmax = 1e3 + 2;

int task, n;

void Solve()
{
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n - 1, 0));
    vector<int> cnt(n, 0);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n - 1; ++j)
        {
            cin >> a[i][j];
            a[i][j]--;
        }
        cnt[a[i][0]]++;
    }
    /*
    mang a:
    0 1
    1 2
    0 2
    mang cnt:
    val  xuathien
    0    2
    1    1

    */
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n - 1; ++j)
        {
           
            cout << a[i][j] << ' ';
        }
        cout << '\n';
        
    }
    cout << '\n';
    int maxx = max_element(cnt.begin(), cnt.end()) - cnt.begin();
    cout << maxx << ' ';
    for (int i = 0; i < n; ++i)
    {
        if (a[i][0] != maxx)
        {
            cout << maxx + 1;
            for (auto y : a[i])
            {
                cout << " " << y + 1;
            }
            cout << "\n";
            return;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> task;
    while (task--)
    {
        Solve();
    }
    return 0;
}