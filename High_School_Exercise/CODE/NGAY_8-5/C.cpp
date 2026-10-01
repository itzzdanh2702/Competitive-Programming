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

int n;
ll a[MAXN];
ll l[MAXN];
ll pos[MAXN];
ll tmp2[MAXN];
ll dem = 0;

int main()
{
    FAST();
    freopen("C.inp", "r", stdin);
    freopen("C.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        pos[a[i]] = i;
    }
    for (int i = 1; i <= n; ++i)
    {
        cin >> l[i];
        tmp2[a[i]] = l[i];
    }
    for (int i = 2; i <= n; ++i)
    {
        if (pos[i] <= pos[i - 1])
        {   
            ll tmp = pos[i - 1] - pos[i];
            ll tmp1;
            tmp1 = tmp / tmp2[i] + 1;
            dem += tmp1;
            pos[i] = pos[i] + tmp1 * tmp2[i];
        }
    }
    cout << dem;
}