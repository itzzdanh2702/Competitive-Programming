#include <bits/stdc++.h>
#define ll long long
using namespace std;
const long long mod = 1000000007;
#define MAXN 1000005
#define oo 1000000000
void FAST()
{
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
}
int n;
string s;
ll H[1005], hs, PW[1005];
ll get(int i, int j){
    return (H[j] - H[i - 1] * PW[j - i + 1] + mod * mod) % mod;
}

int main(){
    FAST();
    cin >> s;
    n = s.size();
    s = " " + s;
    H[0] = 0; hs = 0; PW[0] = 1;
    for(int i = 1; i <= n; ++i){
        H[i] = (H[i - 1] * 31 + (s[i] - 'a' + 1)) % mod;
        PW[i] = (PW[i - 1] * 31) % mod;
        hs = (hs * 31 + (s[i] - 'a' + 1)) % mod;
    }
    /*for(int i = 1; i < n; ++i){
        ll res = get(1, i);
        if(hs % res == 0){
            cout << hs / res;
            return 0;
        }
    }*/
    cout << hs << " " << get(1, 2);
}