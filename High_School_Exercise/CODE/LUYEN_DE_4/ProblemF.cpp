#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define pii pair<ll, ll>
const long long MOD = 1000000007;
#define MAXN 1000005
#define oo 1000000000000000000
void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int TC;

int main()
{
    FAST();
    cin >> TC;
    while (TC--)
    {
        ll tmp1;
        ll dem;
        ll a;
        ll tmp = 1;
        cin >> a;
        if (a > 1)
        {
            dem = 1;
        }
        else
        {
            dem = 0;
        }
        while (tmp <= a)
        {
            tmp *= 2;
            ++dem;
        }
        ll ans = -1;
        for (int i = 0; i <= dem; ++i)
        {
            ll ans1 = 0;
            ll l = 0, r = dem;
            ll tmp = pow(2,i);
            while (l <= r)
            {
                ll mid = (l + r) / 2;
                ll tmp1 = pow(2,mid) + tmp;
                if (tmp1 <= a)
                {
                    if (i != mid)
                    {
                        ans1 = tmp1;
                    }
                    l = mid + 1;
                }
                else
                {
                    r = mid - 1;
                }
            }
            ans = max(ans, ans1);
        }
        ll kq = oo;
        for (int i = 0; i <= dem; ++i)
        {
            ll kq1 = 0;
            ll l = 0, r = dem;
            ll tmp = pow(2,i);
            while (l <= r)
            {
                ll mid = (l + r) / 2;
                ll tmp1 = pow(2,mid) + tmp;
                if (tmp1 >= a)
                {
                    if (mid != i)
                    {
                        kq1 = tmp1;
                    }
                    r = mid - 1;
                }
                else
                {
                    l = mid + 1;
                }
            }
            if(kq1 > 0)
            kq = min(kq, kq1);
        }
        tmp1 = min(a - ans, kq - a);
        cout << tmp1 << '\n';
    }
}