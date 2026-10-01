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

ll n;

bool check(ll n)
{
    for (int i = 2; i <= sqrt(n); ++i)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

void solve(ll n)
{
    while (n > 0)
    {
        if (check(n))
        {
            cout << n << '\n';
        }
        n /= 10;
    }
}
int main()
{
    FAST();
    cin >> n;
    solve(n);
}