#include <bits/stdc++.h>
using namespace std;
long long a[1000005];
int main()
{
    map<string, long long> mp;
    mp["monday"] = 2;
    mp["tuesday"] = 3;
    mp["wednesday"] = 4;
    mp["thursday"] = 5;
    mp["friday"] = 6;
    mp["saturday"] = 7;
    mp["sunday"] = 8;
    long long n;
    cin >> n;
    while (n--)
    {
        long long l, r, p = 0, t, m;
        string s, s1;
        cin >> s >> s1 >> l >> r;
        if (mp[s1] >= mp[s])
            m = mp[s1] - mp[s] + 1;
        else
            m = 8 - mp[s] + mp[s1];
        for (long long i = m; i <= r; i += 7)
        {
            if (i >= l)
            {
                t = i;
                p++;
            }
        }
        if (p == 0)
            cout << "impossible" << endl;
        if (p > 1)
            cout << "many" << endl;
        if (p == 1)
            cout << t << endl;
    }
}