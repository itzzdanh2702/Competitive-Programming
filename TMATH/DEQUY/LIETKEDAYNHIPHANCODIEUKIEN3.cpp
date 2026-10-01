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
ll cnt = 0;
string S[MAXN];
void xuat()
{
    ll dem = 0;
    for (int i = 2; i <= n; ++i)
    {
        if ((a[i] == 1) and (a[i - 1] == 1))
        {
            return;
        }
    }
    ++cnt;
    for (int i = 1; i <= n; ++i)
    {
        S[cnt] += to_string(a[i]);
    }
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
    quaylui(1);
    cout << cnt << '\n';
    for (int i = 1; i <= cnt; ++i)
    {
        cout << S[i] << '\n';
    }
}