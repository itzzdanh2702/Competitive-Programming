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

ll TC;
ll a[MAXN];
ll pre[MAXN];

int main()
{
    cin >> TC;
    while (TC--)
    {
        ll ma = -oo;
        memset(pre, 0, sizeof(pre));
        ll n;
        cin >> n;
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i];
        }
        pre[2] = a[1];
        for(int i = 3 ; i <= n ; ++i)
        {
            pre[i] = min(pre[i - 1],a[i - 1]);
        }
        for(int i = 2 ; i <= n ; ++i)
        {
            ma = max(ma,a[i] - pre[i]);
        }
        if(ma <= 0)
        {
            cout << "UNFIT" << '\n';
        }
        else
        {
            cout << ma << '\n';
        }
    }
}
