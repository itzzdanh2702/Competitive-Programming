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

ll n;
ll a[MAXN], S = 0, cnt = 0, cnt1 = 0;

int main()
{
    freopen("ESUM.INP","r",stdin); 
    freopen("ESUM.OUT","w",stdout); 
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        S += a[i];
        if(a[i] & 1)
            ++cnt; 
        else 
            ++cnt1; 
    }
    if(S % 2 == 0)
    {
        cout << max(0LL,(cnt * (cnt - 1))/2) + max(0LL,(cnt1 * (cnt1 - 1))/2); 
        // n!/k!(n - 2)!; 
        // (n * (n - 1))/2 - 
    }
    else 
    {
        cout << cnt * cnt1; 
    }
}