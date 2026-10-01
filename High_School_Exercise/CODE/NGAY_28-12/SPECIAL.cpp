#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
#define MAXN 100000
#define oo 1000000000
#define ll long long
void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
int n;
int a[MAXN];
vector<int> v;

int main()
{
    FAST();
    freopen("SPECIAL.inp","r",stdin);
    freopen("SPECIAL.out","w",stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
    {
        auto it = lower_bound(a + 1, a + n + 1, i);
        if (n - (it - a) + 1 == i)
        {
            v.push_back(i);
        }
    }
    if (v.size() == 0)
        cout << "-1";
    else
    {
        for (auto it : v)
        {
            cout << it << ' ';
        }
    }
}