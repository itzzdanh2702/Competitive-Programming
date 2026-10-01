#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n, k, kq[11], d[11];
int a[11], b[11];
int cnt = 0;
int cnt1 = 0;
ll ans[11];
ll ans1 = 1;
void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
void xuat()
{
    ++cnt1;
    for (int j = 1; j <= k; ++j)
        cout << kq[j] << ' ';
    cout << endl;
}

void dequy(int i)
{
    for (int j = 1; j <= cnt; ++j)
        if (d[b[j]] > 0)
        {
            kq[i] = b[j];
            --d[b[j]];
            if (i < k)
                dequy(i + 1);
            else if (i == k)
            {
                xuat();
            }
            ++d[b[j]];
        }
}

int main()
{
    FAST();
    cin >> k >> n;
    for(int i = 1 ; i <= 10 ; ++i)
    {
        d[i] = 0;
    }
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        d[a[i]]++;
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] != a[i - 1])
        {
            ++cnt;
            b[cnt] = a[i];
        }
    }
    dequy(1);
    cout << cnt1;
}