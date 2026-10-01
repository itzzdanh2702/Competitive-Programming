#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
#define MAXN 1000005
#define oo 1000000000
#define ll long long
#define fi first
#define se second
void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
map<char, ll> mp;
string S;
vector<char> v;
ll ma = -oo;
char ans;
int main()
{
    freopen("STRING.inp", "r", stdin);
    freopen("STRING.out", "w", stdout);
    cin >> S;
    for (int i = 0; i < S.size(); i++)
    {
        mp[S[i]]++;
    }
    for (auto x : mp)
    {
        ma = max(ma, x.se);
    }
    for (char x = 'a'; x <= 'z'; x++)
    {
        if (mp[x] == ma)
            v.push_back(x);
    }
    for(auto x:v)
    cout<<x<<' ';
}
