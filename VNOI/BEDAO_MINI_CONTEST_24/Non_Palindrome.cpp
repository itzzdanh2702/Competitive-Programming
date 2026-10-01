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

int n;
map<char, int> mp;
string S;

int main()
{
    FAST();
    cin >> n;
    cin >> S;
    for (int i = 0; i < S.size(); ++i)
        ++mp[S[i]];
    if (mp.size() == 1)
        return cout << 1, 0;
    string T = S;
    reverse(S.begin(), S.end());
    if (S == T)
        cout << n - 1;
    else
        cout << n;
}
