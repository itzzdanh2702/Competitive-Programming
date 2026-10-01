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

string S[101];
int n;
int ma = -1;
map<string,int> mp;

int main(int argc, char const *argv[])
{
    FAST();
    cin >> n;
    for(int i = 0 ; i < n ; ++i)
    {
        cin >> S[i];
    }
    for(int i = 0 ; i < n ; ++i)
    {
        string tmp;
        for(int j = 0 ; j < n ; ++j)
        {
            tmp += S[i][j];
        }
        ++mp[tmp]; 
    }
    for(auto x : mp)
    {
        ma = max(ma,x.se);
    }
    cout << ma;
    return 0;
}
