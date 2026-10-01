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
ll cnt[27];
string S;

bool cmp(pair<char, ll> x, pair<char, ll> y)
{
    return x.se < y.se;
}
int main()
{
    FAST();
    cin >> TC;
    while (TC--)
    {
        bool check = 0;
        ll cnt1 = 0;
        map<char, ll> mp;
        cin >> S;
        for (int i = 0; i < S.size(); ++i)
        {
            ++mp[S[i]];
        }

        for (auto x : mp)
        {
            ++cnt1;
            cnt[cnt1] = x.se;
        }
        sort(cnt + 1, cnt + cnt1 + 1);
        if (mp.size() < 3)
        {
            cout << "Dynamic" << '\n';
            continue;
        }
        else
        {
            if (cnt[3] != cnt[2] + cnt[1])
                check = 1;
            if (mp.size() >= 4)
                if (cnt[4] != cnt[3] + cnt[2] && cnt[4] != cnt[3] + cnt[1])
                    check = 1;
            for (int i = 5; i <= cnt1; ++i)
            {
                if (cnt[i] != cnt[i - 1] + cnt[i - 2])
                {
                    check = 1;
                }
            }
        }
        if (check == 1)
        {
            cout << "Not" << '\n';
        }
        else
        {
            cout << "Dynamic" << '\n';
        }
    }
}
