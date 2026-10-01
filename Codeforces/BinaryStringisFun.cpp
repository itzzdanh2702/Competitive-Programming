#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define pii pair<ll, ll>
const long long MOD = 998244353;
#define MAXN 1000005
#define oo 1000000000
void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int TC;
int n;
string S;
ll cnt_zero = 0, cnt_one = 0;

ll POW(ll x, ll y)
{
    ll ans = 1;
    for (ll i = 1; i <= y; ++i)
    {
        ans *= x;
        ans %= MOD;
    }
    return ans;
}
void solve(string S)
{
    cnt_zero = 0, cnt_one = 0;
    S = " " + S;
    ll sum = 0;
    ll ans = 1;
    for (ll i = 1; i <= n; ++i)
    {
        if (S[i] == '0')
        {
            ++cnt_zero;
        }
        else
        {
            ++cnt_one;
        }
        if (i == 1)
        {
            sum++;
            continue;
        }
        if (S[i] == '0')
        {
            if (cnt_zero >= i)
            {
                ans *= 2LL;
                ans %= MOD;
                sum += ans;
                sum %= MOD;
            }
            else
            {
                if (cnt_zero == i - 1)
                {
                    sum += ans;
                    ++cnt_zero;
                    sum %= MOD;
                    continue;
                }
                ans /= POW(2LL, i - cnt_zero - 1);
                sum += ans;
                cnt_zero = i;
                sum %= MOD;
            }
        }
        else
        {
            if (cnt_one >= i)
            {
                ans *= 2LL;
                ans %= MOD;
                sum += ans;
                sum %= MOD;
            }
            else
            {
                if (cnt_one == i - 1)
                {
                    sum += ans;
                    ++cnt_one;
                    sum %= MOD;
                    continue;
                }
                ans /= POW(2LL, i - cnt_one - 1);
                sum += ans;
                cnt_one = i;
                sum %= MOD;
            }
        }
        //cout << sum << ' ';
    }
    cout << sum << '\n';
    // cout << S[1] << '\n';
}
int main()
{
    FAST();
    cin >> TC;
    while (TC--)
    {
        cin >> n;
        cin >> S;
        solve(S);
    }
}