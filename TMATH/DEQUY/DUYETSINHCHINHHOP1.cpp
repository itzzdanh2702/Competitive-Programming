#include <bits/stdc++.h>
using namespace std;

int n, kq[11], d[11];
int a[11];
int k;
int cnt = 0;

void xuat()
{
    bool check = 0;
    if (kq[1] != 0)
    {
        for (int j = 1; j <= k - 1; j++)
        {
            if (kq[j] < kq[j + 1])
            {
                check = 1;
            }
            else
            {
                check = 0;
                break;
            }
        }
        if (check == 1)
        {
            ++cnt;
            for (int i = 1; i <= k; ++i)
            {
                cout << kq[i] << ' ';
            }
            cout << '\n';
        }
    }
}

void dequy(int i)
{
    for (int j = 0; j <= n; j++)
        if (d[j] == 0)
        {
            d[j] = 1;
            kq[i] = j;
            if (i < k)
                dequy(i + 1);
            else if (i == k)
            {
                xuat();
            }
            d[j] = 0;
        }
}

int main()
{
    cin >> k >> n;
    for (int i = 1; i <= 10; i++)
        d[i] = 0;
    dequy(1);
    cout << cnt;
}