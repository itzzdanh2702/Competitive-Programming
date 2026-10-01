#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll, ll>
#define fi first
#define se second
#define nmax 1000000
ll m, n, dem;
ll S;
ll a[nmax], b[nmax];
ll tmp[nmax];
pii c[nmax];
bool check[nmax];
deque<pii> de;
bool cmp(pii a, pii b)
{
    if (a.fi != b.fi)
        return a.fi < b.fi;
    else
        return a.se < b.se;
}
int main()
{
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + m + 1, greater<ll>());
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
        c[i].fi = b[i];
        c[i].se = i;
    }
    for (int i = 1; i <= n; i++)
    {
        de.push_back({b[i], i});
    }
    while (!de.empty())
    {
        pii top = de.front();
        de.pop_front();
        for (int i = 1; i <= m; i++)
        {
            if ((a[i] <= top.fi) and (!check[i]))
            {
                check[i] = true;
                tmp[top.se] = a[i];
                S += a[i];
                dem++;
                break;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (tmp[i] != 0)
            cout << tmp[i] << endl;
        else
            cout << "-1" << endl;
    }
    //cout << dem << ' ' << S;
}
