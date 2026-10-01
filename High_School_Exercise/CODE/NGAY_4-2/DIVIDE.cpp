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
ll n;
ll a[MAXN];
int main()
{
    cin >> TC;
    while (TC--)
    {
        cin >> n;
        for (int i = 1; i <= n; ++i)
        {
                cin >> a[i];
            }
        sort(a + 1, a + n + 1);
        ll dem = 1;
        for(int i = 1 ; i <= n ; ++i)
        {
            if(a[i] * dem - (i - 1) > 0)
            continue;
            else 
            {
                ++dem;
            }
        }
        cout << dem << '\n';
    }
}