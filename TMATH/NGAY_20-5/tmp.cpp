#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 40;

vector<ll> a(N);

int main()
{
    a[0] = 0;
    for(int i = 1; i < N; ++i)
        a[i] = 2 * a[i - 1] + i + 2;
    ll n;
    cin >> n;
    for(int i = N - 1; i > 0; --i) {
        if (n > a[i - 1] and n <= a[i - 1] + i + 2) {
            if (n == a[i - 1] + 1) return cout << 'm', 0;
            return cout << 'o', 0;
        }
        if (n > a[i - 1] + i + 2)
            n -= a[i - 1] + i + 2;
    }
    return 0;
}
