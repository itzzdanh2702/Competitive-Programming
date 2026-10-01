#include <bits/stdc++.h>
using namespace std;

int n, kq[13], d[13];
int cnt = 0;

void xuat()
{
    ++cnt;
    if(cnt == 1000000)
    {
        for (int i = 1; i <= n; ++i)
        {
            cout << kq[i] << ' ';
        }
    }
}

void dequy(int i)
{
    for (int j = 1; j <= n; ++j)
        if (d[j] == 0)
        {
            d[j] = 1;
            kq[i] = j;
            if (i == n)
            {
                xuat();
            }
            else
                dequy(i + 1);
            d[j] = 0;
        }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= 12; i++)
        d[i] = 0;
    dequy(1);
}
