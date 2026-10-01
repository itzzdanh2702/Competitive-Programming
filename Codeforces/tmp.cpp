#include <bits/stdc++.h>
using namespace std;
#define MAXN 4 * 100005
void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
int TC;
int n, x;
int a[MAXN], b[MAXN];
int tmp[MAXN];
int d[MAXN];
vector<int> pass_a, pass_b, fail_a, fail_b, ans[MAXN];
int main()
{
    FAST();
    cin >> TC;
    while (TC--)
    {
        pass_a.clear(), pass_b.clear(), fail_a.clear(), fail_b.clear();
        for (int i = 1; i <= n; ++i)
            d[tmp[i]] = 0;
        for (int i = 1; i <= n; ++i)
            ans[tmp[i]].clear();
        int cnt = 0;
        cin >> n >> x;
        for(int i = 1; i <= n; ++i)
        {
            cin >> a[i]; 
            tmp[i] = a[i];
        }
        for (int i = 1; i <= n; ++i)
            cin >> b[i];
        sort(a + 1, a + n + 1);
        sort(b + 1, b + n + 1);
        int pos = 1;
        for (int i = 1; i <= n; ++i)
            if (a[i] > b[pos])
            {
                pass_a.push_back(a[i]);
                pass_b.push_back(b[pos]);
                ++pos;
                ++cnt;
            }
            else
                fail_a.push_back(a[i]);
        if (cnt < x)
            cout << "NO" << '\n';
        else
        {
            for (int i = pos; i <= n; ++i)
                fail_b.push_back(b[i]);
            int it = 0;
            for (int i = cnt - x; i < pass_a.size(); ++i)
            {
                ans[pass_a[i]].push_back(pass_b[it]);
                ++it;
            }
            for (int i = 0; i <= cnt - x - 1; ++i)
                fail_a.push_back(pass_a[i]);
            for (int i = it; i < pass_b.size(); ++i)
                fail_b.push_back(pass_b[i]);
            sort(fail_a.begin(), fail_a.end());
            sort(fail_b.begin(), fail_b.end());
            bool ok = 1;
            for (int i = 0; i < fail_a.size(); ++i)
            {
                ans[fail_a[i]].push_back(fail_b[i]);
                if (fail_a[i] > fail_b[i])
                {
                    ok = 0;
                    break;
                }
            }
            if (!ok)
                cout << "NO" << '\n';
            else
            {
                cout << "YES" << '\n';
                for (int i = 1; i <= n; ++i)
                {
                    cout << ans[tmp[i]][d[tmp[i]]] << ' ';
                    ++d[tmp[i]];
                }
                cout << '\n';
            }
        }
    }
}
