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
ll n, dem;
ll a[nmax], b[nmax];
ll sum = 0;
ll ma = -oo;
ll S;
int main()
{
    FAST();
    //freopen("MAXSEQ.inp", "r", stdin);
    //freopen("MAXSEQ.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        b[i] = a[i];
        sum = max(a[i], sum + a[i]);
        ma = max(ma, sum);
    }
    cout << ma << ' ';
    sort(b + 1, b + n + 1);
    for (int i = 1; i <= n; i++)
    {
        if (b[i] <= 0)
        {
            dem++;
        }
        else
        {
            S += b[i];
        }
    }
    if (dem == n)
    {
        cout << b[n];
    }
    else
    {
        cout << S;
    }
}
