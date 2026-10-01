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

int d[MAXN],dp[MAXN];
int TC;  

int main()
{
    freopen("SODB.inp","r",stdin); 
    freopen("SODB.out","w",stdout); 
    FAST(); 
    //d[1] = 1; 
    for(int i = 1 ; i <= 1e6 ; ++i)
    {
        for(int j = i ; j <= 1e6 ; j += i)
        {
            d[j] += 1; 
        }
    }
    for(int i = 1 ; i <= 1e6 ; ++i)
    {
        dp[i] = dp[i - 1];
        if(d[i] == 4)
            dp[i] += 1;
    }
    cin >> TC; 
    while(TC--)
    {
        int l,r;
        cin >> l >> r; 
        cout << dp[r] - dp[l - 1] << '\n'; 
    }
}
//