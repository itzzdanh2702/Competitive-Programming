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

ll n, k;
ll ans = 0;

int main()
{
    FAST();
    cin >> n >> k;
    if (k % 2 == 0)
        return cout << k / 2, 0;
    ll capso = 2;
    ll remain = n - n / 2;
    ans = n / 2;
    ll tmp;
    if (k == 1)
    {
        while (remain > 0)
        {
            ans += remain / 2;
            remain -= remain / 2;
            if (remain == 2)
                return cout << ans + 2, 0;
        }
    }
    else
    {
        while (remain > 0)
        {
            if ((k - 1) % capso != 0)
            {
                ll pos = (k - 1) / (capso / 2) + 1;
                return cout << ans - (tmp / 2 - pos / 2), 0;
            }  
            else
            {
                capso *= 2;
                ans += remain / 2;
                tmp = remain;
                remain -= remain / 2;
            }
        }
    }
}
/*
1 2 3 4 5 6 7 8 9 10
1 3 5 7 9
1 5 9
1 9
*/
