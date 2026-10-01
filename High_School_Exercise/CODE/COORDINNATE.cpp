#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define pii pair <int, int>
#define pil pair <ll, ll>
#define fi first
#define se second
#define tupi tuple <int, int, int>
#define inf 0x3f3f3f3f
const ll nx = 59;
const ll bx = 109;
const ll mod = 1e9+7;
const ll oo = 1e9;
int n, m, x, y, k;
ll a[nx][nx], dp[nx][nx][bx];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> m >> n >> x >> y >> k;
    dp[m+1][n+1][0] = 1;
    for (int u = 1; u <= k; u++){
        for (int i = 1; i <= 2*m+1; i++){
            for (int j = 1; j <= 2*n+1; j++){
                for (int t = 0; t <= 3; t++){
                    dp[i][j][u] += dp[i+dx[t]][j+dy[t]][u-1];
                    dp[i][j][u] %= mod;
                }
            }
        }
    }
    cout << dp[m+1+x][n+1+y][k];
}