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

ll n;
ll store[2022];
ll S = 0;

int main()
{
    FAST();
    cin >> n;
    store[0] = 0;
    for (int i = 1; i <= 2021; ++i)
    {
        store[i] = store[i - 1] + (i * i) % 2021;
    }
    cout << (((n / 2021) * store[2021]) % 2021 + (store[n % 2021] % 2021)) % 2021;
}