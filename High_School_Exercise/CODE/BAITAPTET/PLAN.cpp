#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
#define ll long long
#define MAXN 1000005
#define oo 1000000000
void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll m, n, k;
ll t[MAXN], p[MAXN];
ll min_time;

bool check(ll val)
{
    ll dem = 0;
    ll kq = 0;
    multiset<ll,greater<ll>> ans;
    for (int i = 1; i <= m; ++i)
    {
        if (t[i] > val)
        {
            continue;
        }
        else
        {
            ans.insert((val - t[i]) / p[i] + 1);
        }
    }
    for (auto x : ans)
    {
        ++dem;
        if (dem <= n)
        {
            kq += x;
        }
        else
        {
            break;
        }
    }
    if(kq >= k) return true;
    else return false;
}

int main()
{
    //freopen("PLAN.inp","r",stdin);
    //freopen("PLAN.out","w",stdout);
    cin >> m >> n >> k;
    for (int i = 1; i <= m; ++i)
    {
        cin >> t[i];
    }
    for (int i = 1; i <= m; ++i)
    {
        cin >> p[i];
    }
    ll l = 1, r = 1e7;
    while (l <= r)
    {
        ll mid = (l + r) / 2;
        if(check(mid))
        {
            r = mid - 1;
            min_time = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << min_time;
}
