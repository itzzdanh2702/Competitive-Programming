#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define pii pair<ll, ll>
const long long MOD = 1000000007;
#define MAXN 1000005
#define oo 1000000000
void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int a[21];
int b[21];
int n;
int dem = 0;

void xuat()
{
    int cnt1 = 0, cnt2 = 0, cnt3 = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] == 0)
        {
            cnt1 += b[i];
        }
        else if (a[i] == 1)
        {
            cnt2 += b[i];
        }
        else
        {
            cnt3 += b[i];
        }
    }
    if ((cnt1 == 0) or (cnt2 == 0) or (cnt3 == 0))
    {
        return;
    }
    if ((cnt1 < cnt3) and (cnt2 < cnt3))
    {
        ++dem;
    }
}
void quaylui(int k)
{
    for (int i = 0; i <= 2; ++i)
    {
        a[k] = i;
        if (k == n)
        {
            xuat();
        }
        else if (k < n)
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
    quaylui(1);
    cout << dem / 2;
}