#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll,ll>
#define fi first
#define se second
const int MAXN = 1e5 + 5; 
const ll oo = 1e18;
ll n,L;
pii a[MAXN]; 

bool cmp(pii a,pii b)
{
    if(a.fi != b.fi)
    return a.fi < b.fi;
    return a.se > b.se; 
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);  
    // freopen("GARDEN.inp","r",stdin);
    // freopen("GARDEN.out","w",stdout); 
    cin >> n >> L; 
    for(int i = 1 ; i <= n ; ++i)
    {
        cin >> a[i].fi >> a[i].se;

    }
    sort(a + 1 , a + n + 1 , cmp);
    ll ma = -1;  
    ll l = 1,r = oo;
    while(l <= r)
    {
        ll sum = 0;
        ll mid = (l + r)/2;
        for(int i = 1 ; i <= n ; ++i)
        {
            if(a[i].fi < mid)
            {
                sum += (mid - a[i].fi + a[i].se - 1) / a[i].se;
            }
        }
        if(sum <= L)
        {
            l = mid + 1;
            ma = mid;
        }
        else 
        {
            r = mid - 1;
        }
    }
    cout << ma; 
}