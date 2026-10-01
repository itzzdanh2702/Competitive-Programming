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

ll POW(int a, int n)
{
    ll ans = 1;
    for(int i = 1 ; i <= n ; ++i)
    {
        ans *= 2; 
        ans %= MOD; 
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    FAST();
    cout << POW(2,100) - 1 + 1000;
    return 0;
}
