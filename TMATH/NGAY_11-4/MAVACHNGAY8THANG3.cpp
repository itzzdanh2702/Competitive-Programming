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

ll n;
ll a[100];
ll arr[3];
void xuat()
{
    bool check = 0;
    ll cnt1 = 0, cnt2 = 0;
    if (a[1] == 3)
    {
        ++cnt1;
    }
    else
    {
        ++cnt2;
    }
    for (int i = 2; i <= n; ++i)
    {
        if (a[i] == 3)
        {
            ++cnt1;
        }
        else if (a[i] == 8)
        {
            ++cnt2;
        }
        if ((a[i] == 8) and (a[i - 1] == 8))
        {
            check = 1;
        }
    }
    if ((cnt1 == cnt2) or (check == 0))
    {
        for (int i = 1; i <= n; ++i)
        {
            cout << a[i] << ' ';
        }
        cout << '\n';
    } 
}

void quaylui(ll k)
{
    for (int i = 1; i <= 2; ++i)
    {
        a[k] = arr[i];
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
    arr[1] = 3;
    arr[2] = 8;
    quaylui(1);
}