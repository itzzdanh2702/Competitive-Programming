#include <bits/stdc++.h>
using namespace std;
#define ll long long
const long long MOD = 1000000007;
#define MAXN 1000005
#define oo 1000000000
void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int n;
int cnt = 0,cnt1 = 0;
int a[21];
int b[21];
ll store[10000000];
int mi = 1e9;
void xuat()
{
    ++cnt;
    int x = 0, y = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] == 0)
        {
            x += b[i];
        }
        else
        {
            y += b[i];
        }
    }
    int tmp = abs(x - y);
    store[cnt] = tmp;
    mi = min(mi, tmp);
   
}

void quaylui(ll k)
{
    for (int i = 0; i <= 1; ++i)
    {
        a[k] = i;
        if (k == n)
        {
            xuat();
        }
        else
        {
            quaylui(k + 1);
        }
    }
}
int main()
{
    FAST();
    cin >> n;

    for (int i = 1; i <= n; ++i)
    {
        cin >> b[i];
    }
    if (n == 2)
    {
        cout << abs(b[2] - b[1]) << ' ' << '1';
        return 0;
    }
    quaylui(1);
    for(int i = 1 ; i <= cnt ; ++i)
    {
        if(store[i] == mi)
        {
            ++cnt1;
        }
    }
    cout << mi << ' ' << cnt1/2;
}