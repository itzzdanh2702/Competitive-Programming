#include <bits/stdc++.h>
using namespace std;
#define ll long long 
ll TC, a, b;
ll x, y, s, e;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> TC;
    while(TC--)
    {
        cin >> x >> y;
        if (x == y and x == 0)
        {
            cout << 0 << endl;
            continue;
        }
        if (x == 0 or y == 0)
        {
            cout << -1 << endl;
            continue;
        }
        s = 0;
        while (x != y)
        {
            if (min(x, y) * 2 > max(x, y))
            {
                e = 2 * min(x, y) - max(x, y);
                s += e;
                x -= e;
                y -= e;
            }   
            else
            {
                if (x < y)
                {
                    x = x * 2;
                    s++;
                }
                else
                {
                    y = y * 2;
                    s++;
                }
            }
        }
        s += min(x,y);
        cout << s << '\n';
    }
}