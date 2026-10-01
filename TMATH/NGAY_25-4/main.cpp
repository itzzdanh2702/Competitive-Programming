#include <bits/stdc++.h>

using namespace std;

template<typename T>
using vi = vector<T>;

int n;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vi<vi<int>> a(n, vi<int>(n)), b(n, vi<int>(n)), c;
    for(auto &u: a)
        for(auto &v: u) cin >> v;
    for(auto &u: b)
        for(auto &v: u) cin >> v;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            if (abs(a[i][j] + b[i][j]) == 1) {
                return cout << -1, 0;
            }
    c = a;
    int ans = INT_MAX;
    for(int k = 0; k < 2; ++k) {
        a = c;
        vi<int> dx(n, 0), dy(n, 0);
        dx[0] = k;
        for(int i = 0; i < n; ++i)
            if (a[0][i] == b[0][i])
                dy[i] = dx[0];
            else
                dy[i] = 1 - dx[0];
        bool ok = true;
        for(int i = 1; i < n; ++i) {
            bool t = -1;
            for(int j = 0; j < n; ++j) {
                if (a[i][j] == b[i][j] and a[i][j] == 0)
                    continue;
                t = j;
                break;
            }
            if (t == -1) dx[i] = 0;
            else if (a[i][t] == b[i][t])
                dx[i] = dy[t];
            else
                dx[i] = 1 - dy[t];
            for(int j = 1; j < n; ++j) {
                if (a[i][j] == b[i][j] and a[i][j] == 0) continue;
                if (a[i][j] != b[i][j] and dx[i] == dy[j])
                    ok = false;
                if (a[i][j] == b[i][j] and dx[i] != dy[j])
                    ok = false;
            }
        }
        int cnt = 0;
        for(int i = 0; i < n; ++i) {
            cnt += dx[i] + dy[i];
            cout << dx[i] << " " << dy[i] << endl;
        }
        if (ok) ans = min(ans, cnt);
    }        
    cout << ans << endl;
    return 0;
}
