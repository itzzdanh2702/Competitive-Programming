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
int ans;

int main()
{
    FAST();
    cin >> n;
    // (k + 1) * ((k - 1)/2 + 1)/2 > ((n + k + 1) * ((n - k - 1)/2 + 1))/2
    ll l = 1, r = n;
    ll en = n - n % 2; 
    while (l <= r)
    {
        ll mid = (l + r) / 2;
        ll tmp = mid - mid % 2; 
        if ((1ll) * (tmp + 2) * ((tmp - 2) / 2 + 1) > (1ll) * ((en + tmp + 1) * ((en - tmp - 1) / 2 + 1)))
        {
            r = mid - 1;
            ans = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << ans;
}