#include <bits/stdc++.h>
#define ll long long
using namespace std;
long long a[1000005], sum[1000005];
int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long n, k;
        cin >> n >> k;
        long long s = 1, r = 0;
        for (long long i = 1; i <= n; i++)
            cin >> a[i];
        for (long long i = 1; i <= n; i++)
        {
            if (a[i] > k)
            {
                r++;
            }
        }
        if (r == 0)
        {
            for (long long i = 1; i <= n; i++)
            {
                sum[i] = sum[i - 1] + a[i];
                if (sum[i] > k)
                {
                    s++;
                    sum[i] = sum[i] - sum[i - 1];
                }
            }
            cout << s << endl;
        }
        else
            cout << -1 << endl;
    }
}