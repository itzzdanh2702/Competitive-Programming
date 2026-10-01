#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, i, k = 1, j;
    pair<long long, long long> a[500005];
    cin >> n;
    for (i = 0; i < n; i++)
        cin >> a[i].second >> a[i].first;
    sort(a, a + n);
    j = a[0].first;
    for (i = 1; i < n; i++)
    {
        if (a[i].second > j)
        {
            k++;
            j = a[i].first;
        }
    }
    cout << k << endl;
    return 0;
}
