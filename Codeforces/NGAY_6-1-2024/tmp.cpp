#include<bits/stdc++.h>

using namespace std;

int64_t dp[19];
int a[19];

int64_t f(int i, bool smaller, bool pos) {
  if (i < 0) {
    return pos;
  }
  if (smaller && pos && dp[i] != -1) {
    return dp[i];
  }
  int64_t ans = 0;
  int lim = smaller ? 9 : a[i];
  for (int d = 0; d <= lim; d++) {
    if (d != 4) ans += f(i - 1, smaller || d < lim, pos || d > 0);
  }
  return smaller && pos ? dp[i] = ans : ans;
}

int64_t solve(int64_t x) {
  int n = 0;
  do {
    a[n++] = x % 10;
    x /= 10;
  } while (x > 0);
  return f(n - 1, 0, 0);
}

void solve() {
  int64_t k;
  cin >> k;
  int64_t lo = 1, hi = 1e18;
  int64_t ans = -1;
  while (lo <= hi) {
    int64_t mid = (lo + hi) / 2;
//    cerr << mid << endl;
    if (solve(mid) >= k) {
      ans = mid;
      hi = mid - 1;
    } else {
      lo = mid + 1;
    }
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  memset(dp, -1, sizeof(dp));
  int tt; cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}
