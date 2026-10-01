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
int cnt = 0;

int main()
{
    FAST();
    cin >> S;
    reverse(S.begin(), S.end());
    for(int i = 0 ; i < S.size() ; ++i)
    {
        cnt += 1; 
        cout << S[i]; 
        i += cnt;
    }
}