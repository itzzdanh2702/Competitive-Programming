#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

typedef vector<vector<long long>> matrix;

matrix operator*(const matrix& a, const matrix& b) {
    int n = a.size(), m = a[0].size(), p = b[0].size();
    matrix c(n, vector<long long>(p));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            for (int k = 0; k < m; k++) {
                c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % MOD;
            }
        }
    }
    return c;
}

matrix pow(matrix a, long long b) {
    int n = a.size();
    matrix ans(n, vector<long long>(n));
    for (int i = 0; i < n; i++) ans[i][i] = 1;
    while (b > 0) {
        if (b & 1) ans = ans * a;
        a = a * a;
        b >>= 1;
    }
    return ans;
}

int main() {
    long long n;
    cin >> n;
    matrix f = {{1, 1}, {1, 0}};
    matrix ans = pow(f, n + 2);
    cout << (ans[0][1] * ans[1][0] % MOD) << endl;
    return 0;
}
