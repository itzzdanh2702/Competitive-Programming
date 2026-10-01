#include<bits/stdc++.h>
using namespace std;
#define MAXN 2 * 10000 + 5
#define ll long long

int TC;
int n;
ll a[MAXN];
ll b[MAXN];

void FAST()
{
    ios_base::sync_with_stdio;
    cin.tie(0);
    cout.tie(0);
}
int main()
{
    FAST();
    cin >> TC;
    while(TC--)
    {
        ll ma = -1;
        cin >> n;
        for(int i = 1 ; i <= n ; ++i)
        {
            cin >> a[i];
        }
        for(int i = 1 ; i <= n ; ++i)
        {
            cin >> b[i];
        }
        sort(a + 1 , a + n + 1);
        sort(b + 1 , b + n + 1);
        for(int i = 1 ; i <= n ; ++i)
        {
            ma = max(ma,a[i] + b[n - i + 1]);
        }
        cout << ma << '\n';
    }
}
