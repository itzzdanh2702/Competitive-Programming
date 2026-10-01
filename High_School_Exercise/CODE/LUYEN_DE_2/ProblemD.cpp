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

bool nt[MAXN]; 
int TC,snt[MAXN],dp[MAXN]; 

void sieve()
{
    for(int i = 1 ; i <= MAXN ; ++i)
        nt[i] = true; 
    nt[0] = nt[1] = false; 
    for(int i = 2 ; i * i <= MAXN ; ++i)
    {
        if(nt[i])   
        {
            for(int j = i * i ; j <= MAXN ; j += i)
                nt[j] = false; 
        }
    }
}
int main()
{
    // freopen("A.INP","r",stdin); 
    // freopen("A.OUT","w",stdout);
    FAST(); 
    sieve(); 
    for(int i = 1 ; i <= 1e6 ; ++i)
    {
        if(nt[i])
            snt[i] = snt[i - 1] + 1; 
        else 
            snt[i] = snt[i - 1]; 
        if(nt[snt[i]])
            dp[i] = dp[i - 1] + 1; 
        else 
            dp[i] = dp[i - 1]; 
    }
    cin >> TC; 
    while(TC--)
    {
        int a,b; 
        cin >> a >> b; 
        cout << dp[b] - dp[a - 1] << '\n'; 
    }
}