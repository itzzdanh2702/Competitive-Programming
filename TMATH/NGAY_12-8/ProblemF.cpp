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

map<int, char> mp;
ll n;
int main(int argc, char const *argv[])
{
    FAST();
    cin >> n;
    mp[0] = 'T';
    mp[1] = 'I';
    mp[2] = 'N';
    mp[3] = 'H';
    mp[4] = 'O';
    mp[5] = 'C';
    mp[6] = 'T';
    mp[7] = 'R';
    mp[8] = 'E';
    ll tmp = (n * (n - 1)) / 2;
    cout << mp[tmp % 9];
    return 0;
}
