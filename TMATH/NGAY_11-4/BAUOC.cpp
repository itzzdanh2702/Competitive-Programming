#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define pii pair<ll, ll>
const long long MOD = 1000000007;
#define MAXN 10000005
#define oo 1000000000
void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

bool check(ll n)
{
    if (n < 2)
    {
        return false;
    }
    for (int i = 2; i <= sqrt(n); ++i)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}
ll n;
ll cnt = 0;
int main()
{
    FAST();
    cin >> n;
    for(int i = 1 ; i <= sqrt(n) ; ++i)
    {
        if(check(i))
        {
            ++cnt;
        }
    }
    cout << cnt;
}