#include <iostream>
using namespace std;

int m, n, a[1010], b[1010];
int F[1010][1010];

int main() {
    ios_base::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
    cin >> m >> n;
    for(int i=2;i<=m+1;++i) cin >> a[i];
    for(int i=2;i<=n+1;++i) cin >> b[i];
    for(int i=2;i<=m+1;++i)
        for(int j=2;j<=n+1;++j) {
            F[i][j] = max( F[i-1][j], F[i][j-1]);
            if(a[i] == b[j])
                F[i][j] = max( F[i][j], F[i-2][j-2] + 1);
        }
    cout << F[m+1][n+1] << endl;
    return 0;
}
