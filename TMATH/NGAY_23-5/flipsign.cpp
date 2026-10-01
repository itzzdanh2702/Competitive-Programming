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
ll a[MAXN];
ll S = 0;
ll mi = oo;
ll dem = 0;
// -4 -3 -2 1
// 
int main()
{
    FAST();
    freopen("DAODAU.inp","r",stdin);
    freopen("DAODAU.out","w",stdout);
    cin >> n;
    for(int i = 1 ; i <= n ; ++i)
    {
        cin >> a[i];
    }
    for(int i = 1 ; i <= n; ++i)
    {
        if(a[i] < 0)
        {
            ++dem;
        }
        mi = min(mi,abs(a[i]));
        S += abs(a[i]);
    }
    if(dem % 2 == 1)
    {
        cout << S - 2 * mi;
    }
    else 
    {
        cout << S;
    }
   
}