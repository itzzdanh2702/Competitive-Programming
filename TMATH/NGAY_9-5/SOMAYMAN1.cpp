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
ll tmp1, tmp2;
int main()
{
    FAST();
    cin >> n;
    if (n % 5 == 0)
    {
        tmp1 = n / 5;
        tmp2 = (n - 3) / 5 + 1;
    }
    else if (n % 5 == 3)
    {
        tmp1 = n / 5 + 1;
        tmp2 = (n - 3) / 5;
    }
    else
    {
        tmp1 = n / 5 + 1;
        tmp2 = (n - 3) / 5 + 1;
    }
    cout << n - (tmp1 + tmp2);
}