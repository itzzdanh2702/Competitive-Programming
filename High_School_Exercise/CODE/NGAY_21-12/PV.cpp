#include <bits/stdc++.h>
using namespace std;
#define ll long long
const long long MOD = 1000000007;
#define nmax 1000005
#define oo 1000000000
void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
ll n;
ll a[nmax];
ll ma = -oo;
vector<ll> v;
int main()
{
    FAST();
    freopen("PV.inp", "r", stdin);
    freopen("PV.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        if (a[i] >= ma)
        {
            ma = max(ma, a[i]);
            v.push_back(i);
        }
    }
    cout << v.size() << endl;
    for (auto x : v)
        cout << x << ' ';
}
