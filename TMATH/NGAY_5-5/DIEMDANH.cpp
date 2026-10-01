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

map<string, int> mp;
string S[MAXN];
string P;
int n;
int main()
{
    FAST();
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        getline(cin, S[i]);
       
    }
    for (int i = 1; i <= n - 1; ++i)
    {
        getline(cin, P);
        ++mp[P];
    }
    for(int i = 1 ; i <= n ; ++i)
    {
        if(mp[S[i]] == 0)
        {
            cout << S[i] << '\n';
        }
    }
}