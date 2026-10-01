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
ll TC;
ll a[MAXN];
ll dp1[MAXN], dp2[MAXN], dp3[MAXN];

int main()
{
    FAST;
    cin >> n >> TC;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    for(int i = 1 ; i <= n ; ++i)
    {
        if(a[i] == 1)
        {
            dp1[i] = dp1[i - 1] + 1;
            dp2[i] = dp2[i - 1];
            dp3[i] = dp3[i - 1];
        }
        else if(a[i] == 2)
        {
            dp1[i] = dp1[i - 1];
            dp2[i] = dp2[i - 1] + 1;
            dp3[i] = dp3[i - 1];
        }
        else 
        {
            dp1[i] = dp1[i - 1];
            dp2[i] = dp2[i - 1];
            dp3[i] = dp3[i - 1] + 1;
        }
    }
    while(TC--)
    {
        ll l,r;
        cin >> l >> r;
        cout << dp1[r] - dp1[l - 1] << ' ' << dp2[r] - dp2[l - 1] << ' ' << dp3[r] - dp3[l - 1];
        cout << '\n';
    }   
}
