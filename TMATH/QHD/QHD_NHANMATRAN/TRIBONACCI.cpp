#include <bits/stdc++.h>
#define ll long long
#define mod 1000000009
using namespace std;

ll T[3][3] = {{1, 1, 1}, {1, 0, 0}, {0, 1, 0}};

void multiply(ll A[3][3], ll B[3][3]) {
    ll C[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            C[i][j] = 0;
            for (int k = 0; k < 3; k++) {
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % mod;
            }
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            A[i][j] = C[i][j];
        }
    }
}

void power(ll F[3][3], ll n) {
    if (n <= 1) {
        return;
    }
    power(F, n / 2);
    multiply(F, F);
    if (n % 2 != 0) {
        multiply(F, T);
    }
}

ll tribonacci(ll n) {
    if (n == 0 || n == 1) {
        return 0;
    }
    if (n == 2) {
        return 1;
    }
    ll F[3][3] = {{1, 1, 1}, {1, 0, 0}, {0, 1, 0}};
    power(F, n - 3);
    return (F[0][0] * 2 % mod + F[0][1] % mod) % mod;
}

int main() {
    ll n;
    while (cin >> n) {
        cout << tribonacci(n) << endl;
    }
    return 0;
}
