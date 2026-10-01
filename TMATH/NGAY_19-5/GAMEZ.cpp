#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define pii pair<ll, ll>
const long long MOD = 1000000007;
#define MAXN 1000005
#define oo 1000000000
void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int n;
int a[MAXN];
int b[MAXN];
int ans;
int pos;
ll pre[MAXN];

int main()
{
    FAST();
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i)
    {
        pre[i] = pre[i - 1] + a[i];
    }
    int l = 1, r = n;
    while (l <= r)
    {
        bool check = 1;
        int mid = (l + r) / 2;
        for (int i = mid + 1; i <= n; ++i)
        {
            if (pre[i - 1] >= a[i])
            {
                continue;
            }
            else
            {
                check = 0;
            }
        }
        if (check)
        {
            r = mid - 1;
            ans = n - mid + 1;
            pos = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << ans << '\n';
    for(int i = 1 ; i <= n ; ++i)
    {
        if(b[i] >= a[pos])
        {
            cout << i << ' '; 
        }
    }
    
}