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
int n, k;
int a[MAXN];
int b[MAXN];
multiset<int> mu[MAXN];
vector<int> ans;

int main()
{
    FAST();
    cin >> TC;
    while (TC--)
    {
        bool check = 0;
        cin >> n >> k;
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i];
            b[i] = a[i];
            int tmp = min(i % k, k - i % k);
            mu[tmp].insert(a[i]);
        }
        sort(a + 1, a + n + 1);
        for (int i = 1; i <= n; ++i)
        {
            int tmp = min(i % k, k - i % k);
            ans.push_back(*mu[tmp].begin());
            mu[tmp].erase(mu[tmp].begin());
        }
        for (int i = 0; i < ans.size(); ++i)
        {
            if (i != ans.size() - 1)
            {
                if (ans[i] > ans[i + 1])
                {
                    cout << "NO" << '\n';
                    check = 1;
                    break;
                }
            }
        }
        for(int i = 0 ; i < k ; ++i)
        {
            mu[i].clear(); 
        }
        ans.clear(); 
        if (check)
            continue;
        cout << "YES" << '\n';
    }
}