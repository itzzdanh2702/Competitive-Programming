#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define pii pair<ll, ll>
const long long MOD = 1000000007;
#define MAXN 1000005
#define oo 1000000000
const int limit = 1e5;

void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll n, p, q;
ll a[MAXN];
ll S = 0;
int cnt = 0;

int main(int argc, char const *argv[])
{
    FAST();
    cin >> n >> p >> q;
    S = p;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        if(a[i] > 0)
        {
            ++cnt;
        }
        S += a[i];
        if (S <= q)
        {
            cout << i << ' ';
            return 0;
        }
    }
    //cout << cnt << ' ';
    if ((S >= p) || (cnt == n))
    {
        cout << "-1";
        return 0;
    }
    // ban dau la p sau do giam xuong S;
    int l = 0, r = limit;
    ll ans = 0;
    int ans1 = 0; 
    // cout << S << ' ';
    while (l <= r)
    {
        bool check = 0;
        int mid = (l + r) / 2;
        // gia su tai lan thuc hien thu mid thi loai tru duoc het tat ca vien da 
        // tinh tong cua thao tac thu mid - 1; 
        ll current_sum = p - 1LL * (mid - 1) * (p - S); 
        for(int i = 1 ; i <= n ; ++i)
        {
            current_sum += a[i]; 
            if(current_sum <= q)
            {
                r = mid - 1;
                ans = 1LL * (mid - 1) * n + i; 
                ans1 = mid;
                check = 1;
                break;
            }
        }
        if(!check)
        {
            l = mid + 1;
        }
    }
    cout << ans;
}
//
