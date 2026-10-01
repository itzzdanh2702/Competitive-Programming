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

int n;
ll a[MAXN];
ll ans[MAXN], S = 0, ma1 = -oo, ma[MAXN];

int main(int argc, char const *argv[])
{
    freopen("BAI5.inp","r",stdin); 
    freopen("BAI5.out","w",stdout);
    FAST();
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        S += a[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        if (i <= 9)
        {
            ans[i] = 0;
            ma[i] = 0;
        }
        else
        {
            ll mi = oo;
            for (int j = i - 9; j <= i; ++j)
                mi = min(mi, a[j]);
            ans[i] = mi + ma[i - 10];
            ma[i] = max(ans[i], ma[i - 1]);
        }
    }
    for (int i = 1; i <= n; ++i)
        ma1 = max(ma1, ans[i]);
    cout << S - ma1;
    return 0;
}





// không thể đến do công việc cá nhân thì mấy hôm mik đá đều có mặt cả hihihaaa, à rồi còn có đôi lúc giật 
// 