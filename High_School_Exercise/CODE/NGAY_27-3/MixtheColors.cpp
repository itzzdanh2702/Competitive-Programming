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

int main()
{
    cin >> TC;
    while(TC--)
    {
        ll dem = 0;
        ll n;
        cin >> n;
        for(int i = 1 ; i <= n ; ++i)
        {
            cin >> a[i];
        }
        sort(a + 1 , a + n + 1);
        for(int i = 2 ; i <= n ; ++i)
        {
            if(a[i] == a[i - 1])
            {
                ++dem;
            }
        }
        cout << dem << '\n';
    }
}