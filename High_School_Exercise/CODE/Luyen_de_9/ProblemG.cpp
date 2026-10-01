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

int main()
{
    FAST();
    int TC;
    cin >> TC;
    while (TC--)
    {
        string S;
        vector<int> network[51];
        char a[51][51];
        int cnt = 0, fr[51] = {0}, ex[51] = {0}, num, ma = -oo;
        cin >> S;
        S = " " + S;
        for (int i = 1; i <= S.size(); ++i)
        {
            a[1][i] = S[i];
            if (a[1][i] == 'Y')
                network[1].push_back(i);
        }
        for (int i = 2; i <= S.size() - 1; ++i)
        {
            for (int j = 1; j <= S.size() - 1; ++j)
            {
                cin >> a[i][j];
                if (a[i][j] == 'Y')
                {
                    network[i].push_back(j);
                }
            }
        }
        for (int i = 1; i <= S.size() - 1; ++i)
        {
            for (int j = 1; j <= S.size() - 1; ++j)
            {
                bool check = 1;
                memset(ex, 0, sizeof(ex));
                if (i == j)
                    continue;
                for (auto x : network[i])
                {
                    if (x == j)
                    {
                        check = 0;
                        break;
                    }
                    ++ex[x];
                }
                if (!check)
                    continue;
                for (auto x : network[j])
                {
                    if (x == i)
                    {
                        check = 0;
                        break;
                    }
                    ++ex[x];
                    if (ex[x] == 2)
                    {
                        ++fr[i];
                        break;
                    }
                }
            }
            if (fr[i] > ma)
            {
                ma = fr[i];
                num = i;
            }
        }
        cout << num << ' ' << ma << '\n';
    }
}