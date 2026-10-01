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

int TC;
int n;
int cnt = 0;
ll store[1000];

int main()
{
    FAST();
    for (int i = 0; i <= 30; ++i)
    {
        for (int j = i + 1; j <= 30; ++j)
        {
            if (i != j)
                store[++cnt] = pow(2, i) + pow(2, j);
        }
    }
    sort(store + 1, store + cnt + 1);
    cin >> TC;
    while (TC--)
    {
        cin >> n;
        int it = lower_bound(store + 1, store + cnt + 1, n) - store;
        int tmp = it - 1;
        cout << min(store[it] - n, n - store[tmp]) << '\n';
    }
}