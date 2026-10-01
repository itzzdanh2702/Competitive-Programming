#include <iostream>
using namespace std;

int n, kq[101], d[101];
int a[101];
int b[101];
int k;

int main()
{
    int tmp = 0;
    cin >> n >> k;
    for (int i = 1; i <= 100; ++i)
        d[i] = 0;
    for (int i = 1; i <= k; ++i)
    {
        cin >> b[i];
    }
    for (int i = k; i >= 1; --i)
    {
        if (b[i] == n)
        {
            --n;
            continue;
        }
        else
        {
            tmp = i;
            break;
        }
    }
    for (int i = 1; i <= k; ++i)
    {
        if (tmp == i)
        {
            b[i] = b[tmp] + 1;
            cout << b[i] << ' ';
        }
        else if (i < tmp)
        {
            cout << b[i] << ' ';
        }
        else
        {
            b[i] = b[i - 1] + 1;
            cout << b[i - 1] + 1 << ' ';
        }
    }
}