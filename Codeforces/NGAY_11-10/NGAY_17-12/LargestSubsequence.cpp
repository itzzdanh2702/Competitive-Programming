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
string S;
pair<char, int> st[MAXN];

bool cmp(pii a, pii b)
{
    if (a.fi == b.fi)
        return a.se < b.se;
    return a.fi > b.fi;
}

int main(int argc, char const *argv[])
{
    FAST();
    cin >> TC;
    while (TC--)
    {
        bool check = 1, ok = 1;
        string ans, ans1;
        int cnt = 1;
        cin >> n;
        cin >> S;
        S = " " + S;
        for (int i = 1; i <= n; ++i)
            st[i] = {S[i], i};
        sort(st + 1, st + n + 1, cmp);
        ans += st[1].fi;
        int tmp = st[1].se;
        int tmp1;
        for (int i = 2; i <= n; ++i)
        {
            if (st[i].se < tmp)
            {
                if (ok)
                {
                    tmp1 = st[i].se;
                    ok = 0;
                    continue;
                }
                if (st[i].se > tmp1)
                {
                    if (st[i].fi == S[tmp1])
                        tmp1 = st[i].se;
                    else
                    {
                        check = 0;
                        break;
                    }
                }
                tmp1 = st[i].se;
                continue;
            }
            ans += st[i].fi;
            tmp = st[i].se;
            ++cnt;
        }
        cout << cnt << ' ';
        if (check)
        {
            int pos;
            for(int i = 0 ; i < ans.size() ; ++i)
                if(ans[i] == ans[0])
                    pos = i;
            cout << cnt - pos - 1 << '\n'; 
        }
        else
            cout << "-1" << '\n';
    }
    return 0;
}
