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

int a, b;

int main(int argc, char const *argv[])
{
    FAST();
    cin >> a >> b;
    int tmp = (a % 8) * 10 + b % 8;
    int tmp1 = (b % 8) * 10 + a % 8;
    if(tmp < tmp1)
    {
        cout << tmp * 2 << ' ' << tmp1 * 2;
    }
    else 
    {
        cout << tmp1 * 2 << ' ' << tmp * 2;
    }
    return 0;
}
