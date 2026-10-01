#include <bits/stdc++.h>
using namespace std;
#define ll long long
const long long MOD = 1000000007;
#define MAXN 2 * 1000005
#define oo 1000000000
void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll m, n;
string S, T;
vector<ll> v[26];
ll mini[MAXN], maxi[MAXN];

int main()
{
    v[1].push_back(2);
    v[1].push_back(3);
    v[1].push_back(4);
    for (auto &x : v[1])
    {
        x = x - 1;
    }
    for(auto &x : v[1])
    {
        cout << x << ' ';
    }
}
