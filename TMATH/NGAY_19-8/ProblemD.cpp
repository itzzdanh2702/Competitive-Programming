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
int a[MAXN];
map<int, int> mp;
void uoc(int n)
{
    ll cnt = 0;
    for (int i = 1; i <= sqrt(n); ++i)
    {
        if (n % i == 0)
        {
            ++cnt;
            int tmp = n / i;
            if (i != tmp)
            {
                ++cnt;
            }
        }
    }
    ++mp[cnt]; 
}
int main()
{
    FAST();
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        uoc(a[i]);
    }
    cout << mp.size() << '\n';
    for(auto x : mp)
    {
        cout << x.fi << ' ' << x.se << '\n';
    }
}