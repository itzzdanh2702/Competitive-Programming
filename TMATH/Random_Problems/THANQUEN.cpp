#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 5005
ll a[maxn];
ll n, i, j, k, tmp, res, tong;
int main()
{

        cin >> n;
        for (i = 0; i < n; i++)
                cin >> a[i];
        sort(a, a + n);
        for (i = 0; i < n - 2; i++)
        {
                for (j = i+1; j < n - 1; j++)
                {
                        tmp = lower_bound(a + j + 1, a + n, a[i] + a[j]) - a;
                        res = res + (tmp - j-1);
                }
        }
        cout << res;
}
