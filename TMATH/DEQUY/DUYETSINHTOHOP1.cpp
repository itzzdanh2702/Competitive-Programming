#include <bits/stdc++.h>
using namespace std;

int n, kq[11], d[11];
int a[11];
int k;
int cnt = 0;

void xuat()
{
    ++cnt;
    for (int j = 1; j <= k; j++)
        cout << a[kq[j]] << ' ';
    cout << endl;
}

void dequy(int i)
{
    for (int j = kq[i - 1] + 1; j <= n; j++)
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
    for (int i = 1; i <= 10; ++i)
        d[i] = 0;

    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    sort(a + 1 , a + n + 1);
    dequy(1);
    cout << cnt;
}