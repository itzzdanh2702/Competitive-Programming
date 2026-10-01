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

ll TC;

void find(ll x, ll val)
{
    ll ans;
    ll l = 1, r = N;
    while (l <= r)
    {
        ll mid = (l + r) / 2;
        if (mid * N - mid * mid < val)
        {
            l = mid + 1;
        }
        else if (mid * N - mid * mid > val)
        {
            r = mid - 1;
        }
        else 
        {
            ans = mid;
        }
    }
}
void chat()
{
    // 
    ll l = 1, r = 1e9;
    while (l <= r)
    {
        ll mid = (l + r) / 2;
        // a * b = mid + 1;
        // a + b = n;
        // a * (n - a) = mid + 1;
        // a * n - a * a = mid + 1;
    }
}
int main()
{
    cin >> TC;
    while (TC--)
    {
        ll N;
        cin >> N;
        cout << lcm(1,N-1) - 1 << ' ';
    }
}