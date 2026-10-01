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
int n, t, dirt;
int sum;
int pos, val;
int a[MAXN];
int cnt = 0;

int main(int argc, char const *argv[])
{
    FAST();
    cin >> TC;
    while (TC--)
    {
        set<int> s;
        cin >> n >> t;
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i];
            if (a[i] & 1)
                s.insert(i);
        }
        while (t--)
        {
            cin >> dirt;
            if (dirt & 1)
            {
                cin >> sum;
                if ((sum - s.size()) % 2 == 0)
                {
                    if (2 * n - s.size() >= sum)
                        cout << "YES" << '\n';
                    else
                        cout << "NO" << '\n';
                }
                else
                {
                    if (s.size() == 0)
                        cout << "NO" << '\n';
                    else
                    {
                        int tmp = 2 * (*s.rbegin() - 1) - (s.size() - 1);
                        // tinh tong tu 1 den rbegin() - 1
                        int tmp1 = 2 * (n - (*s.begin())) - (s.size() - 1);
                        // tinh tong tu s.begin() + 1 den n
                        if (max(tmp, tmp1) >= sum)
                            cout << "YES" << '\n';
                        else
                            cout << "NO" << '\n';
                    }
                }
            }
            else
            {
                cin >> pos >> val;
                if (val == 1)
                {
                    if (a[pos] == 1)
                        continue;
                    a[pos] = 1;
                    s.insert(pos);
                }
                else
                {
                    if (a[pos] == 2)
                        continue;
                    a[pos] = 2;
                    s.erase(pos);
                }
            }
        }
    }
    return 0;
}

