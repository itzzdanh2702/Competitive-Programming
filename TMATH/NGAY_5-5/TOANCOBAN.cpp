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
long long nhan(long long a, long long pow_a, long long M)
{
    if (pow_a == 0)
        return 1;
    ll tmp = nhan(a, pow_a / 2, M);
    if (pow_a % 2 == 0)
    {
        return ((tmp % M) * (tmp % M)) % M;
    }
    else
    {
        return ((((tmp % M) * (tmp % M)) % M) * (a % M)) % M;
    }
}
ll n, m;
int main()
{
    FAST();
    cin >> n >> m;
    if (n < 4)
    {
        int tmp1 = pow(10, n) / m;
        cout << tmp1 % m;
        return 0;
    }
    else
    {
        int dem = 0;
        int tmp = 1;
        while (tmp < m)
        {
            ++dem;
            tmp *= 10;
        }
        int tmp1 = n;
        // cout << nhan(10, tmp1, m);
    }
}