#include <bits/stdc++.h>
using namespace std;
#define ll long long
const long long MOD = 1000000007;
#define MAXN 1000005
#define oo 1000000000
void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int fib (ll n)
{
    if((n == 1) or (n == 2)) return 1;
    return fib(n - 1) + fib(n - 2);
}

ll n;

int main()
{
    FAST();
    cin >> n;
    cout << fib(n);
}