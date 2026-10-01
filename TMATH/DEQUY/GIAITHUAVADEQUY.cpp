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

ll n;
ll ans = 1;
int main()
{
    cin >> n;
    for(int i = 1 ; i <= n ; ++i)
    {
        ans *= i;
    }
    cout << n << '!' << ' ' << '=' << ' ' << ans;
}