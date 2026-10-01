#include <bits/stdc++.h>
#define ll long long

using namespace std;

int t, x, s;
vector<int> vi;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for (int i = 9; i > 0; i--)
    {
        s += i;
        vi.push_back(s);
    }
    cin >> t;
    while (t--)
    {
        cin >> x;
        if (x <= 9)
        {
            cout << x << '\n';
            continue;
        }
        if (x > 45)
        {
            cout << -1 << '\n';
            continue;
        }
        set<int> s;
        auto it = upper_bound(vi.begin(), vi.end(), x);
        --it;
        if (x - *it != 0)
            s.insert(x - *it);
        ll k = 0;
        for (int i = 9; i > 0; i--)
        {
            if (k <= it - vi.begin())
                s.insert(i);
            k++;
        }
        for (auto it : s)
            cout << it;
        cout << '\n';
    }
    return 0;
}