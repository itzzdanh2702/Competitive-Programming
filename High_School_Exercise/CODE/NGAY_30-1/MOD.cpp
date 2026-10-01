#include <bits/stdc++.h>
using namespace std;
#define ll long long
const long long MOD = 1000000007;
#define MAXN 10000005
#define oo 1000000000
vector<ll> ans[MAXN];
void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
ll TC;
ll kq;

// b - b % v chia het cho u
void prepare()
{
    for (int i = 1; i <= 5e5; ++i)
    {
        for (int j = i; j <= 5e5; j += i)
        {
            ans[j].push_back(i);
        }
    }
}

int main()
{
    freopen("MOD.inp", "r", stdin);
    freopen("MOD.out", "w", stdout);
    FAST();
    prepare();
    cin >> TC;
    while (TC--)
    {
        ll kq = 0;
        ll a, b;
        cin >> a >> b;
        for (int v = 1; v <= a; ++v)
        {
            ll tmp = 0;
            ll l = 0, r = ans[b - b % v].size() - 1;
            while (l <= r)
            {
                ll mid = (l + r) / 2;
                if (ans[b - b % v][mid] < v)
                {
                    l = mid + 1;
                    tmp = mid + 1;
                }
                else
                {
                    r = mid - 1;
                }
            }
            kq += tmp;
        }
        cout << kq << endl;
    }
}