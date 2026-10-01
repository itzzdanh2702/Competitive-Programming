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

ll n, k;

int main(int argc, char const *argv[])
{
    FAST();
    cin >> n >> k;
    cout << k / n << '\n'<< k - n * (k / n);
    return 0;
}
