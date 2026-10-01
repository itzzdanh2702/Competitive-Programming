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
ll a[MAXN], b[MAXN];
ll n;
ll cnt1[MAXN],cnt2[MAXN];
int main()
{
    cin >> TC;
    while (TC--)
    {
        ll cnt1 = 0;
        ll cnt2 = 0;
        bool check = 1;
        ll res = 0;
        cin >> n;
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i];
        }
        for (int i = 1; i <= n; ++i)
        {
            cin >> b[i];
        }
        for (int i = 1; i <= n; ++i)
        {
            if (a[i] < b[i])
            {
               cnt1 += b[i] - a[i];
            }
            else if (b[i] < a[i])
            {
               cnt2 += a[i] - b[i];
            }
        }
        if(cnt1 == cnt2)
        {
            cout << cnt1 << '\n';
        }
        else 
        {
            cout << "-1" << '\n';
        }
    }
}
