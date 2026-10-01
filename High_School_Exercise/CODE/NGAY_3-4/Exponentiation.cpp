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

int TC;
ll a, b, pow_a;

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
int main()
{
    cin >> TC;
    while (TC--)
    {
        cin >> a >> pow_a;
        cout << nhan(a, pow_a, MOD) << '\n';
    }
}
