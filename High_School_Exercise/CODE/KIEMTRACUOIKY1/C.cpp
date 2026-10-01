#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
#define nmax 1000005
#define ll long long
#define oo 1000000000
void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
int n, k;
ll a[nmax];
ll b[nmax];
ll am;
ll pos;
map<ll, ll> mp;
int chat(ll x)
{
    ll l = 1, r = n;
    ll ans = -1, mid;
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (a[mid] >= x)
        {
            ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    return ans;
}
int main()
{
    FAST();
    freopen("C.inp","r",stdin);
    freopen("C.out","w",stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= k; i++)
    {
        cin >> b[i];
    }
    for (int i = 1; i <= k; i++)
    {
        ll t = chat(b[i]);
        if (t == -1)
        {
            cout << "1" << ' ';
        }
        else
        {
            if (a[t] == b[i])
            {
                cout << "0" << ' ';
            }
            else
            {
                if ((n - t + 1) % 2 == 0)
                    cout << "1" << ' ';
                else
                    cout << "-1" << ' ';
            }
        }
    }
}
