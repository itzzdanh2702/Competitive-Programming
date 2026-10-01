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

string S;
ll sum;
int dem = 0;
map<char,int> mp;
int main()
{
    FAST();
    cin >> S;
    for(char i = 'a' ; i <= 'z' ; ++i)
    {
        ++dem;
        mp[i] = dem;
    }
    int tmp = mp['a'];
    for(int i = 0 ; i < S.size() ; ++i)
    {
        int tmp1 = abs(mp[S[i]] - tmp);
        sum += min(26 - tmp1,tmp1);
        //abs(mp kt hien tai - mp ky tu truoc)
        //26 - abs(mp kt hien tai - mp ky tu truoc)
        tmp = mp[S[i]];
    }
    cout << sum;

}