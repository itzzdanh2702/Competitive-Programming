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
// "abcdefghijklmnopqrstuvwxyz"
map<char, int> mp;
string S;
ll sum;
int main()
{
    FAST();
    freopen("B.inp", "r", stdin);
    freopen("B.out", "w", stdout);
    cin >> S;
    mp['a'] = 1;
    mp['b'] = 2;
    mp['c'] = 3;
    mp['d'] = 4;
    mp['e'] = 5;
    mp['f'] = 6;
    mp['g'] = 7;
    mp['h'] = 8;
    mp['i'] = 9;
    mp['j'] = 10;
    mp['k'] = 11;
    mp['l'] = 12;
    mp['m'] = 13;
    mp['n'] = 14;
    mp['o'] = 15;
    mp['p'] = 16;
    mp['q'] = 17;
    mp['r'] = 18;
    mp['s'] = 19;
    mp['t'] = 20;
    mp['u'] = 21;
    mp['v'] = 22;
    mp['w'] = 23;
    mp['x'] = 24;
    mp['y'] = 25;
    mp['z'] = 26;
    sort(S.begin(),S.end()); 
    for(int i = 0 ; i < S.size() ; ++i)
    {
        sum += (i + 1) * mp[S[i]]; 
    }
    cout << sum;
}