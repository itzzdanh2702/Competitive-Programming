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

int n, k, a;

int main(int argc, char const *argv[])
{
    cin >> n >> k >> a;
    if (k < (n - a + 1))
    {
        cout << a + k - 1;
    }
    else
    {
        if ((k - (n - a + 1)) % n == 0)
        {
            cout << n;
        }
        else
        {
            cout << (k - (n - a + 1)) % n;
        }
    }
    // a + k - 1;
}
