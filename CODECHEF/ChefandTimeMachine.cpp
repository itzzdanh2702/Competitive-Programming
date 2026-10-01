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

struct tom
{
    ll a, b, c;
};

tom st[MAXN];

bool cmp(tom x, tom y)
{
    return x.c > y.c;
}

ll TC;
ll a[MAXN], b[MAXN], wh[MAXN], bl[MAXN];

int main()
{
    cin >> TC;
    while (TC--)
    {
        multiset<ll> mu1, mu2;
        ll ans = 0;
        ll n, k, m;
        cin >> n >> k >> m;
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i];
            st[i].a = a[i];
        }
        for (int i = 1; i <= n; ++i)
        {
            cin >> b[i];
            st[i].b = b[i];
        }
        for (int i = 1; i <= n; ++i)
        {
            st[i].c = a[i] - b[i];
        }
        for (int i = 1; i <= k; ++i)
        {
            cin >> wh[i];
            mu1.insert(wh[i]);
        }
        for (int i = 1; i <= m; ++i)
        {
            cin >> bl[i];
            mu2.insert(bl[i]);
        }
        sort(st + 1, st + n + 1, cmp);
        for (int i = 1; i <= n; ++i)
        {
            auto it1 = mu1.upper_bound(st[i].c);
            auto it2 = mu2.upper_bound(st[i].c);
            if ((mu1.size() != 0) and (mu2.size() != 0))
            {
                if ((*it1 == *mu1.begin()) and (*it2 == *mu2.begin()))
                {
                    ll tmp1 = st[i].a;
                    ll tmp2 = st[i].b;
                    ans += tmp1 - tmp2;
                    continue;
                }
                if ((*it2 == *mu2.begin()) and (*it1 != *mu1.begin()))
                {
                    ll tmp2 = st[i].b;
                    ll tmp1 = st[i].a - *(--it1);
                    ans += tmp1 - tmp2;
                    mu1.erase(it1);
                    continue;
                }
                if ((*it1 == *mu1.begin()) and (*it2 != *mu2.begin()))
                {
                    ll tmp1 = st[i].a;
                    ll tmp2 = st[i].b + *(--it2);
                    ans += tmp1 - tmp2;
                    mu2.erase(it2);
                    continue;
                }
                ll tmp1 = st[i].a - *(--it1);
                ll tmp2 = st[i].b + *(--it2);
                if (tmp1 - st[i].b < st[i].a - tmp2)
                {
                    mu1.erase(it1);
                    ans += tmp1 - st[i].b;
                }
                else
                {
                    mu2.erase(it2);
                    ans += st[i].a - tmp2;
                }
            }
            else if ((mu1.size() == 0) and (mu2.size() != 0))
            {
                if (*it2 == *mu2.begin())
                {
                    ans += st[i].a - st[i].b;     
                    continue;
                }
                ll tmp2 = st[i].b + *(--it2);
                mu2.erase(it2);
                ans += st[i].a - tmp2;
                continue;
            }
            else if ((mu1.size() != 0) and (mu2.size() == 0))
            {
                if (*it1 == *mu1.begin())
                {
                    ans += st[i].a - st[i].b;
                    continue;
                }
                ll tmp1 = st[i].a - *(--it1);
                mu1.erase(it1);
                ans += tmp1 - st[i].b;
                continue;
            }
        }
        cout << ans << '\n';
    }
}