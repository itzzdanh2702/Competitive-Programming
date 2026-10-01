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

ll m, n;

ll solve(ll p)
{
    ll ans = 0;
    if (p < 10)
        return p;
    ans = p / 10 + 9;
    ll tmp = p;
    while(tmp >= 10)
    {
        tmp /= 10; 
    }
    if((p % 10) < tmp)
    {
        --ans;
    }
    return ans;
}
int main()
{
    FAST();
    cin >> m >> n;
    cout << solve(n) - solve(m - 1); 
}
