
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
#define inf 0x3f

const ll nx = 1e6+9;
const ll bx = 1e3+9;
const ll mod = 1e9+7;

//--------------------------------
int n, q, a[nx], x;
ll dp[nx], mp[nx], sum = 0;

//--------------------------------
int main(){
    // #ifndef ONLINE_JUDGE
    //     freopen("D.Inp", "r", stdin);
    //     freopen("D.Out", "w", stdout);
    // #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        mp[a[i]] = n - a[i];
        dp[0]++; dp[a[i]]--;
        sum += (ll)(n - a[i]);
    }
    for (int i = 1; i <= n; i++){
        dp[i] += dp[i-1];
    }
    for (int i = 1; i <= q; i++){
        cin >> x;
        cout << dp[x] << " " << dp[x] + sum - mp[x] << "\n";
    }
}
/*
Note:

*/