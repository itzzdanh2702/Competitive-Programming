#include <bits/stdc++.h>
using namespace std;
#define ll long long
const long long MOD = 1000000007;
#define MAXN 1000005
#define oo 1000000000
void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll n;
ll TC;
ll pre[MAXN] , pre1[MAXN];
ll a[MAXN];
ll dp[MAXN];

int main()
{
    FAST();
    cin >> TC;
    while (TC--)
    {
        memset(dp, 0, sizeof(dp));
        memset(pre, 0, sizeof(pre));
        memset(pre1, 0, sizeof(pre));
        cin >> n;
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i];
            pre[i] = pre[i - 1] + a[i];
        }
        for (int i = 1; i <= n; ++i)
        {
            ll pos1 = i;
            ll pos2 = i;
            ll l1 = 1, r1 = i;  
            while (l1 <= r1)
            {
                ll mid1 = (l1 + r1) / 2;
                if (a[i] >= pre[i - 1] - pre[mid1 - 1])
                {
                    r1 = mid1 - 1;
                    pos1 = mid1;
                }
                else
                {
                    l1 = mid1 + 1;
                }
            }
            ll l2 = i, r2 = n;
            while (l2 <= r2)
            {
                ll mid2 = (l2 + r2) / 2;
                if (a[i] >= pre[mid2] - pre[i])
                {
                    l2 = mid2 + 1;
                    pos2 = mid2 + 1;
                }
                else
                {
                    r2 = mid2 - 1;
                }
            }
            dp[pos1]++;   
            dp[pos2 + 1]--;
        }
        for(int i = 1 ; i <= n ; ++i)
        {
            pre1[i] = pre1[i - 1] + dp[i]; 
        }
        for(int i = 1 ; i <= n ; ++i)
        {
            cout << pre1[i] << ' ';
        }
    cout << '\n';
    }
}
// 1 2 2 1
// 1 1 2 2 1 
/*
#pragma GCC optimize ("O3")

#include <bits/stdc++.h>

using namespace std;

//---------- Define ------------
#define ll long long
#define ld long double
//------------------------------
#define pii pair <int, int>
#define pli pair <ll, int>
#define pil pair <int, ll>
#define pll pair <ll, ll>
#define fi first
#define se second
//------------------------------
#define tupi tuple <int, int, int>
//------------------------------
#define inf 0x3f3f3f3f

//----------- Const ------------
const ll nx = 1e5+9;
const ll bx = 4e6+9;
const ll kx = 1e3+9;
const ll mod = 1e9+7;

//------ Declare Variable ------
int t, n;
ll a[nx], sum[nx], dp[nx];

//---------- Function ----------
int bsl(int l, int r, int i){
    int res = i;
    while(l <= r){
        int mid = (l + r) >> 1;
        if (sum[i-1] - sum[mid-1] <= a[i]){
            res = max(1, mid);
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    return res;
}

int bsr(int l, int r, int i){
    int res = i;
    while(l <= r){
        int mid = (l + r) >> 1;
        if (sum[mid] - sum[i] <= a[i]){
            res = mid + 1;
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }
    return res;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> t;
    a[0] = 1e9;
    sum[0] = 0;
    while(t--){
        cin >> n;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
        }
        sum[1] = a[1];
        for (int i = 2; i <= n; i++){
            sum[i] = sum[i-1] + a[i];
        }
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; i++){
            dp[bsl(1, i, i)-1]++;
            dp[bsr(i, n, i)+1]--;
        }
        for (int i = 1; i <= n; i++){
            dp[i] += dp[i-1];
            cout << dp[i] - 1 << " ";
        }
        cout << "\n";
    }
}
*/