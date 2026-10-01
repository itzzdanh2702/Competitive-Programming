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

ll n , k;
ll res = 0, dem = 0;
ll a[MAXN], b[MAXN];
map<ll, ll> mp;

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        mp[a[i]]++;
    }
    for (auto x : mp)
    {
        b[++dem] = x.second;
    }
    sort(b + 1 , b + dem + 1 , greater<ll>());
    for (int i = 2; i <= dem; ++i)
    {3
        res += b[i - 1] * 2;
        b[i] -= b[i - 1];
    }
    cout << res;
}