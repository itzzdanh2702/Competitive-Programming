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
    int tmp = (a % 5) * 10 + b % 5;
    int tmp1 = (b % 5) * 10 + a % 5;
    if(tmp < tmp1)
    {
        cout << tmp << ' ' << tmp1;
    }
    else 
    {
        cout << tmp1 << ' ' << tmp;
    }
    return 0;
}
