#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define pii pair<ll, ll>
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
    // freopen("in.inp","r",stdin);
    // freopen("ou.out","w",stdout);
    FAST();
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i].fi >> a[i].se;
    }
    sort(a + 1, a + n + 1);
    sum.push({a[1].se, a[1].fi * a[1].se});
    S = (1ll) * a[1].fi * a[1].se;
    // fi la gia tri se la tong
    for (int i = 2; i <= n; ++i)
    {
        ll len = a[i].fi, wid = a[i].se;
        if (len * wid <= len * max(a[i].se, sum.top().fi) - sum.top().se)
        {
            S += len * wid;
            sum.push({wid, len * wid});
            continue;
        }
        ll tmp = 0, cnt = 0;
        while (!sum.empty())
        {
            if (cnt == 0)
                tmp = a[i].fi * a[i].se;
            else
                tmp = 0;
            ++cnt;
            if (tmp > len * max(wid, sum.top().fi) - sum.top().se)
            {
                wid = max(wid, sum.top().fi);
                S = S + len * wid - sum.top().se;
                sum.pop();
            }
            else
            {
                sum.push({wid, len * wid});
                break;
            }
        }
        if(sum.empty())
            sum.push({wid,len * wid}); 
    }
    cout << S;
}

/*

*/