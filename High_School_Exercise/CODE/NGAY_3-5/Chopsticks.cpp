#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define pii pair<ll, ll>
const long long MOD = 1000000007;
#define MAXN 100005
#define oo 1000000000
void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int n, k;
int dem = 0;
int a[MAXN];
int main()
{
    FAST();
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for(int i = 2 ; i <= n ; ++i)
    {
        if(a[i] - a[i - 1] <= k)
        {
            ++dem;
            ++i;
        }
        else
        {
            continue;
        }
    }
    cout << dem;
}