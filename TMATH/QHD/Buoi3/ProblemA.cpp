#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000005

int s[MAXN];
int a[MAXN];
int n;
int ans = 0;

void sieve()
{
    for (int i = 1; i <= MAXN; ++i)
        for (int j = i; j <= MAXN; j += i)
            s[j] += i;
}
int main()
{
    freopen("PP.inp", "r", stdin);
    freopen("PP.out", "w", stdout);
    sieve();
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        if (s[a[i]] - a[i] > a[i])
            ++ans;
    }
    cout << ans;
    return 0;
}
