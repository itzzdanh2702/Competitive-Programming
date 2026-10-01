#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

using ll = long long;
const int nmax = 2e6 + 5;
const int mod = 1e9 + 7;
#define fi first
#define se second
#define pii pair<ll, ll>
using namespace std;

int n, k;
int a[nmax];

bool check(int M)
{
    int pos = a[1] + M, cnt = 1, i = 1, j;
    while(pos + M < a[n - 1])
    {
        while(pos + M >= a[i])++i;
        pos = a[i] + M;
        cnt++;
    }
    if(cnt <= k) return true;
    pos = a[n] - M, i = n, cnt = 1;
    while(pos - M > a[2])
    {
        while(pos - M <= a[i])--i;
        pos = a[i] - M;
        cnt++;
    }
    if(cnt <= k) 
    return true;
     return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen("TPS.inp", "r", stdin);
    freopen("TPS.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + 1 + n);
    a[++n] = 1e6 + a[1];
    cin >> k;
    int l = 0, r = 1e6, mid, ans;
    while(l <= r){
        mid = r + l >> 1;
        if(check(mid)){
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    cout << ans;
}
