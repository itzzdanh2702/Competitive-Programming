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

int n;
ll pre[MAXN]; 
ll ans = 1;

int main(int argc, char const *argv[])
{
    FAST();
    freopen("message.inp","r",stdin);
    freopen("message.out","w",stdout);
    cin >> n;
    pre[1] = 1; 
    for(int i = 2 ; i <= n ; ++i)
    {
        if(i % 2 == 0)
        {   
            pre[i] = 2 * pre[i - 1]; 
            ans += pre[i]; 
        }
        else 
        {
            pre[i] = pre[i - 1]; 
            ans += pre[i];
        }
    }
    cout << ans;
    return 0;
}
