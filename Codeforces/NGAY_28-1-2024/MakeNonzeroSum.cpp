#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define pii pair<ll, ll>
const long long MOD = 1000000007;
#define MAXN 2 * 100005
#define oo 1000000000
void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int TC;
int n;
int a[MAXN];
int pre[MAXN];
string ans[MAXN];
map<int, int> new_pos1, new_pos2;

string get(int S)
{
    return to_string(S);
}

int main(int argc, char const *argv[])
{
    FAST();
    cin >> TC;
    while (TC--)
    {
        int pos;
        bool check = 0;
        cin >> n;
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i];
            if (i & 1)
                pre[i] = pre[i - 1] + a[i];
            else
                pre[i] = pre[i - 1] - a[i];
            // lay max(new_pos1[pre[i]],new_pos2[pre[i]])
            // new_pos2 luu nhung so bang so doi cua pre[i]
        }
        
        for (int i = 1; i <= n; ++i)
        {
            if (((i & 1) && (pre[n] == -pre[i])) || (((i % 2 == 0) && (pre[n] == pre[i]))))
            {
                pos = i;
                check = 1;
                break;
            }
        }
        if (!check)
            cout << "-1" << '\n';
        else
        {
            cout << 2 << '\n';
            cout << 1 << ' ' << pos << '\n';
            cout << pos + 1 << ' ' << n << '\n';
        }
    }   
    return 0;
}
