#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define pii pair<ll,ll>
#define MAXN 50005
void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int n;
ll S = 0;
pii a[MAXN];
priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> sum;

int main()
{
    //freopen("in.inp","r",stdin); 
    //freopen("ou.out","w",stdout); 
    FAST();
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i].fi >> a[i].se;
    }
    sort(a + 1, a + n + 1);
    sum.push({a[1].se, a[1].fi * a[1].se});
    S = a[1].fi * a[1].se;
    // fi la gia tri se la tong
    for (int i = 2; i <= n; ++i)
    {
        if (a[i].fi * a[i].se > max(sum.top().fi, a[i].se) * a[i].fi - sum.top().se)
        {
            S = S - sum.top().se + max(sum.top().fi, a[i].se) * a[i].fi;
            pii tmp = sum.top();
            if (!sum.empty())
            {
                sum.pop();
            }
            sum.push({max(tmp.fi, a[i].se), max(tmp.fi, a[i].se) * a[i].fi});
        }
        else
        {
            sum.push({a[i].se, a[i].fi * a[i].se});
            S += a[i].fi * a[i].se;
        } 
    }
    cout << S; 
}

/*
    
*/