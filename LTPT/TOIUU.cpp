#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MAXN = 1e5;
const int MAXS = 1e7;

int n, q;
int a[MAXN+5];
int F[MAXS+5];

// Tinh toan cac gia tri H(a[i..j])
void precompute() {
    memset(F, 0, sizeof(F));
    F[0] = 1;
    int S = 0;
    for (int i = 1; i <= n; i++) {
        S += a[i];
        for (int x = S; x >= a[i]; x--) {
            F[x] |= F[x-a[i]];
        }
    }
}

int main() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    precompute();
    for (int i = 1; i <= q; i++) {
        int l, r;
        cin >> l >> r;
        int ans = 1;
        for (int x = 1; x <= MAXS; x++) {
            if (!F[x]) {
                ans = x;
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
