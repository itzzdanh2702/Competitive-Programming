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

int TC;
string S;
set<char> s;
int main()
{
    FAST();
    cin >> TC;
    while (TC--)
    {
        s.clear();
        cin >> S;
        for (int i = 0; i < S.size(); ++i)
        {
            if (S[i + 1] != S[i])
            {
                s.insert(S[i]);
            }
            else 
            {
                ++i;
            }
        }
        for(auto x : s)
        {
            cout << x;
        }
        cout << '\n'; 
    }
}