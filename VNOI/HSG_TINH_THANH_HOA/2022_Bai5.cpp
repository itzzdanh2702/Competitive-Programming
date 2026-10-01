#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define MAXN 1000005
#define oo 100000000000
void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll n, current_pos, k;
ll lb, tmp_pos;    
ll ans = 0, pre_ans = 0;
ll ma = -oo;
pair<ll, ll> x[MAXN];

ll dist(ll a, ll b)
{
    ll tmp;
    if (x[a].fi * b > 0)
        tmp = abs(x[a].fi - b);
    else
        tmp = abs(x[a].fi) + abs(b);
    return tmp;
}

int main(int argc, char const *argv[])
{
    freopen("MARIO.inp", "r", stdin);
    freopen("MARIO.out", "w", stdout);
    FAST();
    cin >> n >> current_pos >> k;
    for (int i = 1; i <= n; ++i)
        cin >> x[i].fi >> x[i].se;
    sort(x + 1, x + n + 1);
    ll tmp = k / 3;
    for (int i = 1; i <= n; ++i)
    {
        if (current_pos >= x[i].fi)
            lb = i;
        else
        {
            if (dist(i, current_pos) <= k)
            {
                tmp_pos = i;
                ans += x[i].se;
            }
            else
                break;
        }
    }
    ll tmp_ans = 0; 
    for(int i = lb ; i >= 1 ; --i)
    {
        if(dist(i,current_pos) <= k)
            tmp_ans += x[i].se; 
        else 
            break;
    }
    ma = tmp_ans; 
    ll it = lb;
    for (int i = tmp_pos; i >= lb + 1; --i)
    {
        ll tmp1 = dist(i, current_pos);
        while (it >= 1)
        {
            if (tmp1 > tmp)
            {
                if (dist(it, current_pos) <= (k - tmp1) / 2)
                {
                    pre_ans += x[it].se;
                    --it;
                }
                else
                    break;
            }
            else
            {
                if (dist(it, current_pos) <= (k - 2 * tmp1))
                {
                    pre_ans += x[it].se;
                    --it;
                }
                else
                    break;
            }
        }
        ma = max(ma, ans + pre_ans);
        ans -= x[i].se;
    }
    cout << ma;
    return 0;
}
