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
int dir, n, q;
int l, r;
int pos;
int a[MAXN];
int ans[MAXN][4];
int dp[MAXN], dp1[MAXN];
int cnt = 0;
vector<int> v,v1;
bool check = 0;
multiset<int,greater<int>> left_val, right_val;

int sum(int k)
{
    int S = 0;
    while (k > 0)
    {
        S += k % 10;
        k /= 10;
    }
    return S;
}

int main()
{
    FAST();
    cin >> TC;
    while (TC--)
    {
        cnt = 0;
        check = 0;
        left_val.clear();
        right_val.clear();
        cin >> n >> q;
        for (int i = 1; i <= n; ++i)
            cin >> a[i];
        for (int i = 1; i <= n; ++i)
        {
            ans[i][0] = a[i];
            int tmp = sum(a[i]);
            ans[i][1] = tmp;
            if (tmp < 10)
            {
                ans[i][2] = tmp;
                ans[i][3] = tmp;
                continue;
            }
            int tmp1 = sum(tmp);
            ans[i][2] = tmp1;
            if (tmp1 < 10)
            {
                ans[i][3] = tmp1;
                continue;
            }
            int tmp2 = sum(tmp1);
            ans[i][3] = tmp2;
        }
        while (q--)
        {
            cin >> dir;
            if (dir == 1)
            {
                check = 1;
                ++cnt;
                cin >> l >> r;
                left_val.insert(l);
                right_val.insert(r + 1); 
                v.push_back(*left_val.begin());
                v1.push_back(*right_val.begin()); 
            }
            // 
            else
            {
                cin >> pos;
                sort(v.begin(),v.end()); 
                sort(v1.begin(),v1.end()); 
                auto it = upper_bound(v.begin(),v.end(),pos);
                auto it1 = upper_bound(v1.begin(),v1.end(),pos);
                if(it == v.begin())
                {
                    cout << ans[pos][0] << '\n';
                    continue;
                }
                int tmp = (it - v.begin()) - 1;
                int tmp1 = (it1 - v1.begin()) - 1;
                if(tmp > 3)
                {
                    cout << ans[pos][3] << '\n';
                }
                else 
                {
                    cout << ans[pos][tmp - tmp1] << '\n';
                }
            }
        }
        v.clear(); 
        v1.clear(); 
    }
}