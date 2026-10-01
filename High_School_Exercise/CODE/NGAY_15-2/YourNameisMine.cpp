#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second

using namespace std;

ll t;
string a, b;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--)
    {
        int j = 0;
        cin >> a >> b;
        if (a.size() == b.size())
        {
            if (a == b)
                cout << "YES" << '\n';
            else cout << "NO" << '\n';
            continue;
        }
        else if (a.size() < b.size())
            swap(a, b);
        for (int i = 0 ; i < a.size() ; i++)
        {
            if (a[i] == b[j])
                j++;
        }
        if (j == b.size()) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}