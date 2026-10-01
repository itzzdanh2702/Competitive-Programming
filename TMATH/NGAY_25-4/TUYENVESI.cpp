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

ll a[21];
ll b[21];
ll dem = 0;
int n, l, r, x;

void xuat()
{
    ll P = 0;
    ll mi = oo;
    ll ma = -1; 
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] == 1)
        {
            P += b[i]; 
            if(b[i] > ma)
            {
                ma = b[i]; 
            }
            if(b[i] < mi)
            {
                mi = b[i]; 
            }
        }
    }
    if((P >= l) and (P <= r))
    {
        if(ma - mi >= x)
        {
            ++dem;
        }
    }
}
void quaylui(int k)
{
    for (int i = 0; i <= 1; ++i)
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
    cin >> n >> l >> r >> x;
    for (int i = 1; i <= n; ++i)
    {
        cin >> b[i];
    }
    quaylui(1);
    cout << dem;
}