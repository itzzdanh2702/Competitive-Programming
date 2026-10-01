#include <bits/stdc++.h>
using namespace std;

int n, kq[16], d[16];
int a[16];
int k;
int cnt = 0;
long long fact[16];
void factorial()
{
    fact[0] = 1;
    for (int i = 1; i <= 15; ++i)
    {
        fact[i] = fact[i - 1] * i;
    }
}
void xuat()
{
    for (int j = 1; j <= k; j++)
        cout << kq[j] << ' ';
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
    factorial();
    cin >> n >> k;
    for (int i = 1; i <= 10; ++i)
        d[i] = 0;
    cout << fact[n] / (fact[k] * fact[n - k]) << '\n';
    dequy(1);
}