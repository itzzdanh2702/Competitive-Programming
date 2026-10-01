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
ll arr[100];
ll cnt = 0;
ll mi = oo;

void xuat()
{
    ll S = 0 , P = 0 , Q = 0;
    for(int i = 1 ; i <= n ; ++i)
    {
        if(a[i] == 0)
        {
            S += arr[i];
        }
        else if (a[i] == 1)
        {
            ++P;
        }
        else if (a[i] == 2)
        {
            Q += arr[i];
        }
    }
    if(S == Q)
    {
        mi = min(mi,P);
    }
}

void quaylui(ll k)
{
    for (int i = 0; i <= 2; ++i)
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
        cin >> arr[i];
    }
    quaylui(1);
    cout << mi;
}