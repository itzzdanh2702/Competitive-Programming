#include <bits/stdc++.h>
using namespace std;
long long a[1000005];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        long long l = 1, res = 0, m = 0;
        for (int r = 1; r <= n; r++)
        {
            m++;
            while (a[r] < m)
            {
                l++;
                m--;
            }
            res += (r - l + 1);
        }
        cout << res << '\n';
    }
    /*
    i = 1
    {
    l = 1;
    m = 1;
    a[1] < m ktm;
    res = 1;
    }
    i = 2;
    {
    l = 1;
    m = 2;
    a[2] < m t/m --> l = 2 , m = 1;
    res = 1;
    }
    i = 3;
    {
        l = 2;
        m = 2;
        a[3] < m ktm 
        res = 2;

    }
    i = 4;
    {
        l = 2;
        m = 3;
        a[3] < m tm;
        l = 3 , m = 2;
    }
    }
    }
    */
}