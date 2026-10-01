#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
#define MAXN 1000005
#define oo 1000000000

void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

long long n, t, u;
long long a[MAXN];
multiset<long long> mu;

int main()
{
    FAST();
    cin >> n >> t;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        mu.insert(a[i]);
    }

    while (t--)
    {
        cin >> u;
        auto it = mu.upper_bound(u);
        if (*it - *mu.begin() == 0)
        {
            cout << "-1" << endl;
            continue;
        }
        cout << *(--it) << '\n';
        mu.erase(it);
    }
}