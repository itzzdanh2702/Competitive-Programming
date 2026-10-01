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
ll a[MAXN];
ll pre[MAXN];
long double ans1 = -1;
long double store[MAXN];
int main()
{
    freopen("homework.inp", "r", stdin);
    freopen("homework.out", "w", stdout);
    FAST();
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }
    for (int k = 1; k <= n - 2; ++k)
    {
        ll tmp = pre[n] - pre[k];
        ll mi = oo;
        for (int j = k + 1; j <= n; ++j)
        {
            mi = min(mi, a[j]);
        }
        long double ans = (tmp - mi)/(n - k - 1);   
        ans1 = max(ans1,ans);
        store[k] = ans;
    }
    for(int i = 1 ; i <= n - 2 ; ++i)
    {
        if(store[i] == ans1)
        {
            cout << i << '\n';
        }
    }
}