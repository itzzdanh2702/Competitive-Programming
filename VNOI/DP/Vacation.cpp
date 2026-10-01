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

int n;
int a[MAXN], b[MAXN], c[MAXN];
ll hp_a[MAXN], hp_b[MAXN], hp_c[MAXN], ans = -oo;

int main()
{
    FAST();
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i] >> b[i] >> c[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        hp_a[i] = max(hp_b[i - 1], hp_c[i - 1]) + a[i];
        hp_b[i] = max(hp_a[i - 1], hp_c[i - 1]) + b[i];
        hp_c[i] = max(hp_a[i - 1], hp_b[i - 1]) + c[i];
        ans = max({ans, hp_a[i], hp_b[i], hp_c[i]});
    }
    cout << ans; 
}