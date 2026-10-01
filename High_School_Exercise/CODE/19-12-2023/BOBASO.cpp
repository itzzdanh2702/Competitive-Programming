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
ll ans = 0;

int main(int argc, char const *argv[])
{
    FAST();
    cin >> n >> k;
    ans += pow(n / k, 3);
    if (k % 2 == 0)
    {
        int remain = n % k;
        if (remain < k / 2)
            ans += pow((n - remain) / k, 3);
        else
            ans += pow((n - remain) / k + 1, 3);
        // (n - (remain - k/2) - k/2)/k + 1
    }

    cout << ans;
    // tinh so luong so chia het cho k;
    // tinh so luong so chia cho k du k/2;
    return 0;
}
// abcdffff 
// ffffabcd