/*
┏━━━━━━━━━━━━━━━━━━━━┓
*   By Trung113395   *
┗━━━━━━━━━━━━━━━━━━━━┛
*/
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define fi first
#define se second
const ll nx = 1e5 + 9;
const ll bx = 1e9 + 6;
const ll mod = 1e9 + 7;
ll x, y, a, b, c, p[nx], q[nx], r[nx], p1[nx], q1[nx], ans = 0;
bool check = 0;
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> x >> y >> a >> b >> c;
    for (ll i = 1; i <= a; i++)
    {
        cin >> p[i];
    }
    for (ll i = 1; i <= b; i++)
    {
        cin >> q[i];
    }
    for (ll i = 1; i <= c; i++)
    {
        cin >> r[i];
    }
    sort(p + 1, p + 1 + a, greater<ll>());
    sort(q + 1, q + 1 + b, greater<ll>());
    sort(r + 1, r + 1 + c, greater<ll>());
    for (ll i = 1; i <= x; i++)
    {
        p1[i] = p[i];
    }
    for (ll i = 1; i <= y; i++)
    {
        q1[i] = q[i];
    }
    sort(p1 + 1, p1 + 1 + x);
    sort(q1 + 1, q1 + 1 + y);
    if (x < y)
    {
        for (ll i = 1; i <= x; i++)
        {
            if (p1[i] >= r[i] && q1[i] >= r[i])
            {
                check = 1;
                break;
            }
            else
            {
                if (p1[i] < q1[i])
                {
                    if (p1[i] < r[i])
                        p1[i] = r[i];
                }
                else
                {
                    if (q1[i] < r[i])
                        q1[i] = r[i];
                }
            }
        }
        if (check == 0)
        {
            for (ll i = x + 1; i <= y; i++)
            {
                if (q1[i] >= r[i])
                {
                    check = 1;
                    break;
                }
                else
                    q1[i] = r[i];
            }
        }
    }
    else
    {
        for (ll i = 1; i <= y; i++)
        {
            if (p1[i] >= r[i] && q1[i] >= r[i])
            {
                check = 1;
                break;
            }
            else
            {
                if (p1[i] < q1[i])
                {
                    if (p1[i] < r[i])
                        p1[i] = r[i];
                }
                else
                {
                    if (q1[i] < r[i])
                        q1[i] = r[i];
                }
            }
        }
        for (int i = 1; i <= x; ++i)
        {
            cout << p1[i] << ' ';
        }
        cout << '\n';
        if (check == 0)
        {
            for (ll i = y + 1; i <= x; i++)
            {
                if (p1[i] >= r[i])
                {
                    check = 1;
                    break;
                }
                else
                {
                    if (p1[i] < r[i])
                        p1[i] = r[i];
                }
            }
        }
    }

    for (ll i = 1; i <= max(x, y); i++)
    {
        // cout << p1[i] << " " << q1[i] << "\n";
        ans += p1[i] + q1[i];
    }
    cout << ans;
}