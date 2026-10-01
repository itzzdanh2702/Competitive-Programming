#include <bits/stdc++.h>
using namespace std;
long long chan[200002], le[200002], n, a[200002], k;
map<long long, long long> mp;
vector<long long> ds;
//--
void sub12()
{
    long long ans = 0, x, y;
    for (int i = 1; i < n; i++)
        for (int j = i + 1; j <= n; j++)
        { // check: a[i] .. a[j]
            x = chan[j] - chan[i - 1];
            y = le[j] - le[i - 1];
            if (x > 0 and y > 0 and 0 <= x - y and x - y <= k)
                ans++;
        }
    cout << ans << endl;
}
//--
void sub3()
{
    long long ans = 0, e;
    mp.clear();
    mp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        e = chan[i] - le[i];
        ans += mp[e];
        mp[e]++;
    }
    cout << ans << endl;
}
//--
void sub4()
{
    long long ans = 0, e, x;
    bool u, v;
    u = v = false;
    mp[0] = 1;
    for (int i = 1; i <= n; i++)
    { // a[j],..., a[i]
        if (a[i] % 2 == 0)
            u = true;
        else
            v = true;
        e = chan[i] - le[i];
        if (i > 1 and (a[i] + a[i - 1]) % 2 == 1)
        {
            for (int t = 0; t < ds.size() - 1; t++)
                mp[ds[t]]++;
            x = ds[ds.size() - 1];
            ds.clear();
            ds.push_back(x);
        }
        if (u and v)
            for (int t = 0; t <= k; t++)
                ans += mp[e - t];
        ds.push_back(e);
    }
    cout << ans;
}
//--
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("Daysodep.Inp", "r", stdin);
    // freopen("Daysodep.Out", "w", stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        chan[i] = chan[i - 1];
        le[i] = le[i - 1];
        if (a[i] % 2 == 0)
            chan[i] += a[i];
        else
            le[i] += a[i];
    }
    sub12();
    return 0;
}
