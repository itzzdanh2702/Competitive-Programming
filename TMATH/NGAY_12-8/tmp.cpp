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

ll X1, X2, Y1, Y2;
int n;
map<char, ll> mp;
string S;

int main(int argc, char const *argv[])
{
    FAST();
    cin >> X1 >> Y1 >> X2 >> Y2;
    cin >> n;
    cin >> S;
    S = " " + S;
    for (int i = 1; i <= n; ++i)
        ++mp[S[i]];
    ll cnt_left = 0, cnt_right = 0, cnt_up = 0, cnt_down = 0;
    cnt_left = mp['L'];
    cnt_right = mp['R'];
    cnt_up = mp['U'];
    cnt_down = mp['D'];
    ll ans = -1;
    ll tmp6 = X1, tmp7 = Y1;
    ll l = 0, r = oo;
    while (l <= r)
    {
        ll mid = (l + r) / 2;
        ll tmp = mid / n;
        ll tmp1 = mid - tmp * n;
        X1 = tmp6 + (cnt_right - cnt_left) * tmp;
        Y1 = tmp7 + (cnt_up - cnt_down) * tmp;
        for (int i = 1; i <= tmp1; ++i)
        {
            if (S[i] == 'L')
                --X1;
            if (S[i] == 'R')
                ++X1;
            if (S[i] == 'U')
                ++Y1;
            if (S[i] == 'D')
                --Y1;
        }
        ll dist = abs(X2 - X1) + abs(Y2 - Y1);
        if (dist <= mid)
        {
            ans = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
        X1 = tmp6, Y1 = tmp7;
    }
    cout << ans;
    return 0;
}
