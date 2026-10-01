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

int TC;
int n;
int a[MAXN];
map<int, int> mp;

int main()
{
    FAST();
    cin >> TC;
    while (TC--)
    {
        mp.clear();
        int res = -1;
        cin >> n;
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i];
            ++mp[a[i]]; 
        }
        for(auto x : mp)
        {
            if(x.se > res)
            {
                res = x.se;
            }
        }
        if((res <= 1) and (n >= 2))
        {
            cout << "-1" << '\n';
        }
        else if (res == n)
        {
            cout << "0" << '\n';
        }
        else 
        {
            cout << n - res + 1 << '\n'; 
        }
    }
}