//LaziChicken - 4/2023

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define pii pair <int, int>
#define pll pair <ll, ll>
#define pli pair <ll, int>
#define pil pair <int, ll>
#define fi first
#define se second
#define dim 3
#define tupi tuple <int, int, int>
#define inf 0x3f3f3f3f

const ll nx = 1e6+9;
const ll bx = 1e3+9;
const ll mod = 1e9+7;

//--------------------------------
int t;
bool check[nx];
ll n, m, sum, pw[nx], kq = 0;
vector <int> res;

ll mu(ll a, ll n){
    if (!n) return 1;
    ll tam = mu(a, n >> 1);
    tam = (tam * tam) % mod;
    if (n & 1) tam = (tam * a) % mod;
    return tam;
}

void solve(){
    cin >> n >> m;
    res.clear(); sum = kq = 0;
    if (n * (n - 1) / 2 < m){
        cout << -1 << "\n";
        return;
    }
    for (int i = 1; i <= n; i++){
        check[i] = 0;
    }
    int pre = 0;
    for (int i = 1, j = 1; i <= n; i++){
        while (j - i < max(0LL, m - sum - (n - i - 1LL) * (n - i) / 2LL)){
            j++;
        }
        if (j == pre) break;
        check[j] = 1;
        res.emplace_back(j);
        sum += (j - i);
        pre = j;
    }
    for (int i = n; i >= 1; i--){
        if (!check[i]) res.emplace_back(i);
    }
    for (int i = 0; i < res.size(); i++){
        (kq += res[i] * pw[i]) %= mod;
    }
    cout << kq << "\n";
}

//--------------------------------
int main(){
    #ifdef ONLINE_JUDGE
        freopen("Invert.Inp", "r", stdin);
        freopen("Invert.Out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    pw[0] = 1;
    for (int i = 1; i <= 1e6; i++){
        pw[i] = (pw[i-1] * 2LL) % mod;
    }
    cin >> t;
    while(t--){
        solve();
    }
}
/*
Note:

*/