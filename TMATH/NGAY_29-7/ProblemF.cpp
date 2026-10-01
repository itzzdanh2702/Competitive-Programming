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

ll store[21];
ll a,b;

void prepare()
{
    store[0] = 1;
    for (int i = 1; i <= 20; ++i)
    {
        store[i] = store[i - 1] * i;
    }
}
ll A(int k, int n)
{
    return store[n] / store[n - k];
}

int main(int argc, char const *argv[])
{
    FAST();
    prepare();
    cin >> a >> b;
    cout << A(b,a);
    return 0;
}
