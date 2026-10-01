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

ll n,TC;
ll a[MAXN];
ll dp[MAXN];
int main()
{
    cin >> n >> TC;
    for(int i = 1 ; i <= n ; ++i)
    {
        cin >> a[i];
        if(a[i] > 0)
        {
            dp[i] = dp[i - 1] + 1;
        }
        else 
        {
            dp[i] = dp[i - 1];
        }
    }
    while(TC--)
    {
        ll m;
        cin >> m;
        cout << dp[m] << '\n';
    }
}