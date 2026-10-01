#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define pii pair<ll, ll>
const long long MOD = 1000000007;
#define MAXN 10000005
#define oo 1000000000
void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int n;
ll a[MAXN];
ll f[MAXN];
ll g[MAXN];
ll ans = -oo;

int main()
{
    FAST();
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] > a[i - 1])
        {
            f[i] = f[i - 1] + 1;
        }
        else
            f[i] = 1;
    }
    for (int i = n; i >= 1; --i)
    {
        if (a[i] > a[i + 1])
        {
            g[i] = g[i + 1] + 1;
        }
        else
            g[i] = 1;
    }
    for(int i = 1 ; i <= n ; ++i)
    {
        ans = max(ans,g[i] + f[i] - 1);
    }
    cout << ans;
}


/*
    2 2 1 4 6 
    2 1 1 4 6 
    1 1 1 4 6 
    1 1 1 1 6 
    1 1 1 1 1  
*/