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
string S;
map<char, int> mp;

int main()
{
    FAST();
    cin >> n;
    cin >> S;
    S = " " + S;
    for(int i = 1 ; i <= n ; ++i)
    {
        ++mp[S[i]]; 
    }
    if(mp['B'] == mp['A'] + mp['C'])
    {
        cout << "YES"; 
    }
    else 
    {
        cout << "NO";
    }
    
}