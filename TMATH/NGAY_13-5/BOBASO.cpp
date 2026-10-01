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

int p, q;
ll dem = 0;
int main()
{
    FAST();
    cin >> p >> q;
    for (ll i = 0; i <= MAXN; ++i)
    {
        if (i > p)
        {
            break;
        }
        for (ll j = 0; j <= MAXN; ++j)
        {
            if (i + j > p)
            {
                break;  
            }
            for (ll k = 0; k <= MAXN; ++k)
            {
                if ((i * j * k <= q) && (i + j + k <= p))
                {
                    ++dem;
                }
                else
                {
                    break;
                }
            }
        }
    }
    cout << dem;
}