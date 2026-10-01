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
ll p;
ll st;
ll t;
ll pre[MAXN];
ll ans[MAXN];
ll mi = 1e9;
int main()
{
    FAST();
    freopen("A.inp","r",stdin);
    freopen("A.out","w",stdout);
    cin >> n;
    for(int i = 2 ; i <= n ; ++i)
    {
        cin >> p;
        if(p == 1)
        {
            cin >> st;
            pre[i] = st; 
            ans[i] = pre[i] - pre[i - 1]; 
        } 
        else if (p == 2)
        {
            cin >> st >> t;
            //-->pre[i] - pre[st] = t;
            //pre[i - 1] + ans[i] - pre[st] = t
            //ans[i] = t + pre[st] - pre[i - 1];
            //pre[i] = pre[i - 1] + ans[i];
            ans[i] = t + pre[st] - pre[i - 1];
            pre[i] = pre[i - 1] + ans[i]; 
        }
    }
    for(int i = 2 ; i <= n ; ++i)
    {
        mi = min(mi,ans[i]);
    }
    for(int i = 2 ; i <= n ; ++i)
    {
        if(ans[i] == mi)
        {
            cout << ans[i] << ' ' << i - 1 << ' ' << i;
            return 0;
        }
    }

}