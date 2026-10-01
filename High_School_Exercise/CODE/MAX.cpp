#include <bits/stdc++.h>
#define ll long long 

using namespace std;

const int mod = 1e6 + 7;

int m, n;
char a[2005][2005];
string dp[2005][2005], b[2005][2005];

int main()
{  
    freopen("MAX.inp","r",stdin);
    freopen("MAX.out","w",stdout);

    cin >> m >> n;
    for(int i = 1; i <= m; ++i){
        for(int j = 1; j <= n; ++j){
            cin >> a[i][j];
        }
    }
    for(int i = 1; i <= m; ++i){
        for(int j = 1; j <= n; ++j){
            b[i][j] = max(b[i - 1][j], b[i][j - 1]) + a[i][j];
        }
    }
    ll ans = 0, pw = 1;
    string tmp = b[m][n];
    for(int i = tmp.size() - 1; i >= 0; --i){
        if(tmp[i] == '1'){
            ans = (ans + pw) % mod;
        }
        pw = (pw * 2) % mod;
    }
    cout << ans;
    
    cout << '\n';
    return 0;
}