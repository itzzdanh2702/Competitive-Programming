#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define pii pair<ll, ll>
const long long MOD = 1000000007;
#define MAXN 100005
#define oo 1000000000
void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int x, y, a, b, c;
int p[MAXN], q[MAXN], r[MAXN];
ll sum1 = 0, sum2 = 0;
int main()
{
    FAST();
    cin >> x >> y >> a >> b >> c;
    for (int i = 1; i <= a; ++i)
    {
        cin >> p[i];
    }
    for (int i = 1; i <= b; ++i)
    {
        cin >> q[i];
    }
    sort(p + 1, p + a + 1);
    sort(q + 1, q + b + 1);
    for (int i = 1; i <= a; ++i)
    {
        if (i >= a - x + 1)
        {
            sum1 += p[i];
        }
    }
    for (int i = 1; i <= b; ++i)
    {
        if (i >= b - y + 1)
        {
            sum2 += q[i];
        }
    }
    for (int i = 1; i <= c; ++i)
    {
        cin >> r[i];
    }
    for (int i = 1; i <= c; ++i)
    {
        int it1 = lower_bound(p + 1,p + a + 1,r[i]) - p;
        int it2 = lower_bound(q + 1,q + b + 1,r[i]) - q;
        
    }
}
