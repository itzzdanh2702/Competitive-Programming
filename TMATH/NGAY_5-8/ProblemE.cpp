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

int tong(ll n)
{
    int S = 0;
    while (n > 0)
    {
        S += n % 10;
        n /= 10;
    }
    return S;
}
int main(int argc, char const *argv[])
{
    FAST();
    cin >> n;
    if (tong(n) == 1)
    {
        cout << 10;
    }
    else
        cout << tong(n);
    return 0;
}
