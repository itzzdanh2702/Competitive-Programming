#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nmax 1000000
string S;
ll a, b;
int main()
{
    freopen("GCD.inp", "r", stdin);
    freopen("GCD.out", "w", stdout);
    cin >> a >> b;
    cout << __gcd(a, b);
}
// 1 2 3 4 5