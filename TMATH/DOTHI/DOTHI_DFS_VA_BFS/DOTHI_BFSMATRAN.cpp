#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll m, n, x, y, z = 0, t = 1e18, b[205][205], c[205][205];
ll a[205][205];
ll f1[4] = {0, 0, 1, -1};
ll f2[4] = {1, -1, 0, 0};
void bfs(ll u, ll v)
{
    queue<pair<ll, ll>> hao;
    b[u][v] = 1;
    c[u][v] = 1;

    for (ll i = 0; i < 4; ++i)
    {
        u += f1[i];
        v += f2[i];
        if (u >= 1 && u <= n && v >= 1 && v <= m)
        {
            if (a[u][v] == a[u - f1[i]][v - f2[i]])
            {
                b[u][v] = 0;
                c[u][v] = 0;
            }
            else if (a[u][v] < a[u - f1[i]][v - f2[i]])
            {
                b[u][v] = 1;
            }
            else if (a[u][v] > a[u - f1[i]][v - f2[i]])
            {
                c[u][v] = 1;
            }
            hao.push({u, v});
        }
        u -= f1[i];
        v -= f2[i];
    }
    while (hao.size())
    {
        ll h = hao.front().first;
        ll c1 = hao.front().second;
        hao.pop();
        for (ll i = 0; i < 4; ++i)
        {
            h += f1[i];
            c1 += f2[i];
            if (h >= 1 && h <= n && c1 >= 1 && c1 <= m)
            {
                if (a[h][c1] < a[h - f1[i]][c1 - f2[i]] && b[h][c1] > c[h - f1[i]][c1 - f2[i]] + 1)
                {
                    b[h][c1] = c[h - f1[i]][c1 - f2[i]] + 1;
                    hao.push({h, c1});
                }
                if (a[h][c1] > a[h - f1[i]][c1 - f2[i]] && c[h][c1] > b[h - f1[i]][c1 - f2[i]] + 1)
                {
                    c[h][c1] = b[h - f1[i]][c1 - f2[i]] + 1;
                    hao.push({h, c1});
                }
                if (a[h][c1] == a[h - f1[i]][c1 - f2[i]])
                {
                    ll check = 0;
                    if (b[h][c1] > b[h - f1[i]][c1 - f2[i]])
                    {
                        b[h][c1] = b[h - f1[i]][c1 - f2[i]];
                        hao.push({h, c1});
                        check++;
                    }
                    if (c[h][c1] > c[h - f1[i]][c1 - f2[i]])
                    {
                        c[h][c1] = c[h - f1[i]][c1 - f2[i]];
                        if (check == 0)
                            hao.push({h, c1});
                    }
                }
            }

            h -= f1[i];
            c1 -= f2[i];
        }
    }
}
int main()
{
    cin >> n >> m >> x >> y;
    for (ll i = 1; i <= n; ++i)
    {
        for (ll j = 1; j <= m; ++j)
        {
            cin >> a[i][j];
            b[i][j] = c[i][j] = 1e18;
        }
    }
    bfs(x, y);
    b[x][y] = c[x][y] = 0;
    if (b[n][m] == 1e18 && c[n][m] != 1e18)
        cout << c[n][m];
    else if (c[n][m] == 1e18 && b[n][m] != 1e18)
        cout << b[n][m];
    else if (c[n][m] != 1e18 && b[n][m] != 1e18)
        cout << min(b[n][m], c[n][m]);
    else
        cout << -1;
}
