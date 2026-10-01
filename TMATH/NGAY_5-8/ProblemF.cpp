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

int n, a, b, c;

int main(int argc, char const *argv[])
{
    FAST();
    cin >> n >> a >> b >> c;
    int tmp = (a * b) / __gcd(a, b);
    int tmp1 = (b * c) / __gcd(b, c);
    int tmp2 = (c * a) / __gcd(c, a);
    int tmp3 = (tmp1 * tmp2) / __gcd(tmp1, tmp2);
    cout << n / tmp + n / tmp1 + n / tmp2 - 3 * (n / tmp3);
    return 0;
}
