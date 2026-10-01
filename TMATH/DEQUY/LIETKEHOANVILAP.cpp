#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n, kq[11], d[10];
int a[11],b[11];
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

void fact()
{
    ans[1] = 1;
    for(int i = 2 ; i <= 10 ; ++i)
    {
        ans[i] = i * ans[i - 1];
    }
}

void xuat()
{
    ll S = 0;
    ++cnt1;
    for (int j = 1; j <= n; ++j)
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
            if(i < n)
            dequy(i + 1);
            else if(i == n)
            {
                xuat();
            }
            ++d[b[j]];
        }
}

int main()
{
    FAST();
    fact();
    cin >> n;
    for(int i = 1 ; i <= n ; ++i)
    {
        cin >> a[i];
    }
    sort(a + 1 , a + n + 1);
    for(int i = 1 ; i <= n ; ++i)
    {
        if(a[i] != a[i - 1])
        {
            ++cnt;
            b[cnt] = a[i];
        }
    }
    //for(int i = 1 ; i <= cnt ; ++i)
    //{
        //ans1 *= ans[d[b[i]]];
    //}
   // cout << ans[n]/ans1 << '\n';
    dequy(1);
}
