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
int s[2];
int a[MAXN];

int main()
{
    FAST();
    cin >> TC;
    while (TC--)
    {
        vector<pair<int, int>> v;
        vector<int> v1, v2;
        cin >> n;
        cin >> s[0] >> s[1];
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i];
            v.push_back({a[i], i});
        }
        sort(v.begin(), v.end());
        reverse(v.begin(),v.end());
        for (int i = 0; i < v.size(); ++i)
        {
            int tmp1 = s[0] * (v1.size() + 1);
            int tmp2 = s[1] * (v2.size() + 1);
            if (tmp1 < tmp2)
            {
                v1.push_back(v[i].se);
            }
            else
            {
                v2.push_back(v[i].se);
            }
        }
        cout << v1.size() << ' '; 
        for (auto x : v1)
        {
            cout << x << ' ';
        }   
        cout << '\n';
        cout << v2.size() << ' '; 
        for (auto x : v2)
        {
            cout << x << ' ';
        }
        cout << '\n';
    }
}