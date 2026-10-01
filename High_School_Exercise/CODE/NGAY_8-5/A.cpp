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
vector<ll> v;

int main()
{
    FAST();
    freopen("A.inp", "r", stdin);
    freopen("A.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        if ((a[i - 1] > a[i]) and (a[i] < a[i + 1]))
        {
            v.push_back(i);
        }
    }
    cout << v.size() << '\n';
    for (auto x : v)
    {
        cout << x << ' ';
    }
}