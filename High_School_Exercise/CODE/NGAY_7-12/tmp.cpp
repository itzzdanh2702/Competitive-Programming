
//LaziChicken - 10/2023

#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define pii pair <int, int>
#define pli pair <ll, int>
#define pil pair <int, ll>
#define pll pair <ll, ll>
#define tii tuple <int, int, int>
#define fi first
#define se second
#define inf 0x3f

const ll nx = 1e6+2;
const ll bx = 1e3+2;
const ll mod = 1e9+7;

//--------------------------------
int n, m, dp[8][302][302], res = 0;
char a[302][302];

int cost(int dir, int u, int v, int x, int y){
    return dp[dir][x][y] - dp[dir][x][v-1] - dp[dir][u-1][y] + dp[dir][u-1][v-1];
}

bool check(int u, int v, int x, int y){
    for (int i = 1; i <= 7; i++){
        if (!cost(i, u, v, x, y)) return 0;
    }
    return 1;
}

//--------------------------------
int main(){
    if (fopen("CauVong.inp", "r")){
        freopen("CauVong.inp", "r", stdin);
        freopen("CauVong.out", "w", stdout);
    }
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            for (int k = 1; k <= 7; k++){
                dp[k][i][j] = dp[k][i-1][j] + dp[k][i][j-1] - dp[k][i-1][j-1];
            }
            dp[a[i][j]-'0'][i][j]++;
        }
    }
    for (int x = 1; x <= n; x++){
        for (int y = 1; y <= m; y++){
            int v = 1;
            for (int u = x; u >= 1; u--){
                while(v <= y and check(u, v, x, y)) v++;
                res += v - 1;
            }
        }
    }
    cout << res;
}