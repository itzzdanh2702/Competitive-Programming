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
int TC;
int a[MAXN];
int mp[15];
bool check[10][10];

int main()
{
    freopen("COUNT.inp", "r", stdin);
    freopen("COUNT.out", "w", stdout);
    cin >> TC;
    while (TC--)
    {
        memset(mp,0,sizeof(mp));
        int dem = 0;
        for (int i = 1; i <= 10; ++i)
        {
            cin >> a[i];
            mp[a[i]]++;
        }
        for (int i = 1; i <= 9; ++i)
        {
            for (int j = i + 1; j <= 10; ++j)
            {
                dem += mp[a[i]] * mp[a[j]];
            }
        }
        cout << dem << '\n';
    }
}
