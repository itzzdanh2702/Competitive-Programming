#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second

using namespace std;

const int nmax = 105;

int n, ans, kq[nmax];
pair <ll,ll> a[nmax];

int main()
{
    freopen("XAOTRON.inp", "r", stdin);
    freopen("XAOTRON.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1 ; i <= n ; i++)
        cin >> a[i].fi;
    for (int i = 1 ; i <= n ; i++)
        cin >> a[i].se;
    for (int i = 1 ; i <= n ; i++)
    {
        for (int j = 1 ; j <= n ; j++)
        {
            if (a[j].fi == i)
            {
                for (int k = 1 ; k <= n ; k++)
                {
                    if (a[k].fi == j)
                    {
                        ans = k;
                        break;
                    }
                }
                for (int k = 1 ; k <= n ; k++)
                {
                    if (a[k].fi == ans)
                    {
                        kq[k] = a[i].se;
                        break;
                    }
                }
                break;
            }
        }
    }
    for (int i = 1 ; i <= n ; i++)
        cout << kq[i] << '\n';
    return 0;
}