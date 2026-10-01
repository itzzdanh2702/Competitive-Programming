#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nmax 1000000
#define fi first
#define se second
ll b[nmax];
ll pos[nmax];
ll n, dem = 0;
pair<ll, ll> a[nmax];
struct tom
{
    ll fi, se, thir;
} p[nmax];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].fi;
        a[i].se = i;
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
    {
        {
            while (i != a[i].se)
            {
                swap(a[i], a[a[i].se]);
                dem++;
            }
        }
    }
    cout << dem;
}