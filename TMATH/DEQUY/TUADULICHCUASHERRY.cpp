#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n, kq[11], d[11];
int a[11][11];
ll mi = 1e9;
void xuat()
{
    ll tmp = 0;
    for (int j = 2; j <= n; ++j)
    {
        tmp += a[kq[j - 1]][kq[j]];
    }
    mi = min(mi, tmp);
}

void dequy(int i)
{
    for (int j = 1; j <= n; ++j)
        if (d[j] == 0)
        {
            d[j] = 1;
            kq[i] = j;
            if (i < n)
                dequy(i + 1);
            else if (i == n)
            {
                xuat();
            }
            d[j] = 0;
        }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= 10; i++)
        d[i] = 0;
    dequy(1);
    cout << mi;
}