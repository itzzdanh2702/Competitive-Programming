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
int nt[MAXN];
int q;
int l, r;
int cnt = 0;

int main()
{
    cin >> q;
    for (int k = 2; k <= sqrt(q); ++k)
    {
        while (q % k == 0)
        {
            q /= k;
            if (q % k != 0)
            {
                ++cnt;
            }
        }
    }
    cout << cnt;
}