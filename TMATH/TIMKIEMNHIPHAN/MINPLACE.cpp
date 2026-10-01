#include <bits/stdc++.h>
using namespace std;
int n, q;
int t[20001], e[20001], a[20001];
int main()
{
    freopen("Minplaces.Inp", "r", stdin);
    freopen("Minplaces.Out", "w", stdout);
    cin >> q;
    while (q--)
    {
        int kq = 0;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> t[i];
            a[t[i]]++;
        }
        for (int i = 1; i <= n; i++)
        {
            cin >> e[i];
            a[e[i]]--;
        }
        for (int i = 1; i <= 2400; i++)
            a[i] = a[i - 1] + a[i];
        for (int i = 1; i <= 2400; i++)
        {
            kq = max(kq, a[i]);
            a[i] = 0;
        }
        cout << kq << '\n';
    }
}