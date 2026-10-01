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
int main()
{
    FAST();
    cin >> n;
    ll hour = n / 3600;
    ll minute = (n - (hour * 3600)) / 60;
    ll second = n - hour * 3600 - minute * 60;
    cout << hour << ' ' << minute << ' ' << second;
}