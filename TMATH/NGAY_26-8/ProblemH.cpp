#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define pii pair<ll, ll>
const long long MOD = 1000000007;
#define MAXN 1000005
const ll oo = 1e16;
void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll m, n;
ll mi = oo;
vector<ll> v;

void uoc(ll n)
{
    for (int i = 1; i <= sqrt(n); ++i)
    {
        if (n % i == 0)
        {
            v.push_back(i);
            ll tmp = n / i;
            if (tmp != i)
            {
                v.push_back(tmp);
            }
        }
    }
}

int main()
{
    FAST();
    freopen("tongnn.inp", "r", stdin);
    freopen("tongnn.out", "w", stdout);
    cin >> m >> n;
    uoc(n);
    for (int i = 0; i < v.size(); ++i)
    {
        for (int j = 0; j < v.size(); ++j)
        {
            if ((__gcd(v[i], v[j]) == m) && ((v[i] / __gcd(v[i], v[j]) * v[j]) / n == 1))
                mi = min(mi, v[i] + v[j]);
        }
        // cout << v[i] << ' ';
    }
    if (mi == oo)
        cout << "-1";
    else
        cout << mi;
}