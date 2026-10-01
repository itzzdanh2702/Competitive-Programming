#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n, kq[11], b[11], d[11];
int a[11];
int cnt = 0;
int cnt1 = 0;

bool checknt(ll n)
{
    if (n < 2)
    {
        return false;
    }
    for (int i = 2; i <= sqrt(n); ++i)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

void xuat()
{
    ll tmp = 0;
    for (int j = 1; j <= n; ++j)
    {
        if (j == 1)
        {
            tmp += kq[j];
        }
        else
        {
            tmp = tmp * 10 + kq[j];
        }
    }
    if (checknt(tmp))
    {
        ++cnt1;
        cout << tmp << '\n';
    }
}

void dequy(int i)
{
    for (int j = 1; j <= cnt; ++j)
        if (d[b[j]] > 0)
        {
            --d[b[j]];
            kq[i] = b[j];
            if (i < n)
                dequy(i + 1);
            else if (i == n)
            {
                xuat();
            }
            ++d[b[j]];
        }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= 10; i++)
        d[i] = 0;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        ++d[a[i]];
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] != a[i - 1])
        {
            ++cnt;
            b[cnt] = a[i];
        }
    }
    dequy(1);
    if(cnt1 == 0)
    {
        cout << "-1";
    }
}