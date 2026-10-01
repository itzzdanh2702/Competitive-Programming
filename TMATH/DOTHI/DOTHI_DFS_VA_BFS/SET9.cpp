#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
#define MAXN 1000005
#define oo 1000000000
#define TASK ""
#define FILE(X)                     \
    freopen(#X ".INP", "r", stdin); \
    freopen(#X ".OUT", "w", stdout);
 
void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
 
int TC;
string a, b;
 
int main()
{
    FAST();
    cin >> TC;
    while (TC--)
    {
        getline(cin,a);
        getline(cin,b);
        vector<int> v[150];
        for (int i = 0; i < a.size(); i++)
            v[a[i]].push_back(i);
        bool Ok = true;
        for (char x : b)
        {
            if (v[x].empty())
            {
                cout << -1 << "\n";
                Ok = false;
                break;
            }
        }
        if (!Ok)
            continue;
        for (int i = 'a'; i <= 'z'; i++)
            sort(v[i].begin(), v[i].end());
        int res = -1;
        vector<int> ans;
        for (char x : b)
        {
            auto xx = upper_bound(v[x].begin(), v[x].end(), res);
            if (xx == v[x].end())
            {
                ans.push_back(b.size() + 1);
                res = -1;
            }
            else
            {
                int pos = upper_bound(v[x].begin(), v[x].end(), res) - v[x].begin();
                res = v[x][pos];
                ans.push_back(res);
            }
        }
        res = 1;
        for (int i = 0; i < ans.size(); i++)
            //cout << ans[i] << " ";
        cout << "\n";
    }
}