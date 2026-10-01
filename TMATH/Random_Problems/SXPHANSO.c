#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;

bool operator < (pii a, pii b) {
    return double(a.first) / a.second < double(b.first) / b.second;
}

pii a[100005];
int n;

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
        auto tmp = __gcd(a[i].first, a[i].second);
        a[i].first /= tmp;
        a[i].second /= tmp;
    }

    sort(a, a + n);
    for (int i = 0; i < n; ++i) cout << a[i].first << " " << a[i].second << '\n';
}
