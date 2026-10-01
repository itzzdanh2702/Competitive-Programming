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
ll n;
int uoc(ll n)
{
    int dem = 0;
    for (int i = 1; i <= sqrt(n); ++i)
    {
        if (n % i == 0)
        {
            ll tmp = n / i;
            if (tmp == i)
            {
                ++dem;
            }
            else
            {
                dem += 2;
            }
        }
    }
    return dem;
}
int main()
{
    FAST();
    cin >> TC;
    while (TC--)
    {
        cin >> n;
        if(n % 2 == 1)
        {
            cout << 2 * (uoc(n) - 1) << '\n';
        }
        else 
        {
            cout << 2 * (uoc(n) - 1) - 1 << '\n'; 
        }
    }
}