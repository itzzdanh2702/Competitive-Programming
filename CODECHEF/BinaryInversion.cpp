#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define pii pair<ll, ll>
const long long MOD = 1000000007;
#define MAXN 100005
#define oo 1000000000
void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int n, m;
int TC;
int sum = 0;
string S[MAXN];

bool cmp(pair<ll, string> x, pair<ll, string> y)
{
    return x.fi < y.fi;
}
int main()
{
    FAST();
    cin >> TC;
    while (TC--)
    {
        vector<pair<ll, string>> v;
        cin >> n >> m;
        for (int i = 1; i <= n; ++i)
        {
            cin >> S[i];
        }
        for (int i = 1; i <= n; ++i)
        {
            ll cnt = 0;
            for (int j = 0; j < S[i].size(); ++j)
            {
                if (S[i][j] == '1')
                {
                    ++cnt;
                }
            }
            sum += cnt;
            v.push_back({cnt, S[i]});
        }
        sort(v.begin(), v.end());
        for(int i = 0 ; i < v.size() ; ++i)
        {
            ll P = 0;
            P += sum - v[i].fi;
            P += 
        }
    }
}