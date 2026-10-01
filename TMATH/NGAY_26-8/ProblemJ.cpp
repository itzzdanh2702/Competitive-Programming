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

int n;
int a[MAXN], ans[MAXN];
vector<int> v;
vector<int> v1;

int main()
{
    FAST();
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
    {
        int cnt = 0;
        int pos;
        if (a[i] == 0)
            v.push_back(i);
        else
        {
            pos = v.size() - a[i];
            for (int i = 0; i < pos; ++i)
                v1.push_back(v[i]);
            v1.push_back(i);
            for (int i = pos; i < v.size(); ++i)
                v1.push_back(v[i]);
            v.clear();
            v = v1;
            v1.clear();
        }
    }
    for (int i = 0; i < v.size(); ++i)
        ans[v[i]] = i + 1;
    for (int i = 1; i <= n; ++i)
        cout << ans[i] << ' ';
}