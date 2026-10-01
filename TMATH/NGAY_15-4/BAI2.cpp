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

int l, r;
int cnt = 0;

int main()
{
    FAST();
    cin >> l >> r;
    for (int i = l; i <= r; ++i)
    {
        string tmp = to_string(i);
        string tmp1 = "";
        for (int i = tmp.size() - 1; i >= 0; --i)
        {
            tmp1 += tmp[i];
        }
        if (tmp1 == tmp)
        {
            ll dem = 0;
            ll tmp1 = i;
            for (int k = 2; k <= sqrt(tmp1); ++k)
            {
                while (tmp1 % k == 0)
                {
                    tmp1 /= k;
                    if (tmp1 % k != 0)
                    {
                        ++dem;
                    }
                }
            }
            if (tmp1 > 1)
            {
                ++dem;
            }
            if (dem >= 3)
            {
                ++cnt;
            }
        }
    }
    cout << cnt;
}