#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
#define ll long long 
#define MAXN 1000005
#define oo 1000000000
void FAST()
{
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
}
ll n;
ll h[MAXN],b[MAXN],dp[MAXN];
ll ma = -oo;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>h[i];
        //cin>>b[i];
        //dp[i] = b[i];
    }
    for(int i=1;i<=n;i++)
    {
        auto it = upper_bound(h+i+1,h+n+1,h[i]);
        cout<<it-h;
    }
    
   
}

