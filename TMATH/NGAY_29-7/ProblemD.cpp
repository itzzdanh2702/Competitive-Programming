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

int TC;
int n, k;
ll store[21];

void prepare()
{
    store[0] = 1;
    for (int i = 1; i <= 20; ++i)
    {
        store[i] = store[i - 1] * i;
    }
}
ll C(int k, int n)
{
    return store[n] / (store[k] * store[n - k]);
}
int main(int argc, char const *argv[])
{
    FAST();
    prepare();
    cin >> TC;
    while (TC--)
    {
        cin >> n >> k;
        cout << C(k, n) << '\n';
    }
    return 0;
}
