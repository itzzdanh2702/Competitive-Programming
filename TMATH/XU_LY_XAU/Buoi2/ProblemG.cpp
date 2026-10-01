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

int main()
{
    FAST();
    cin >> TC;
    while (TC--)
    {
        bool check = 0;
        int cnt = 0;
        string tmp = "2020";
        cin >> n;
        cin >> S;
        S = " " + S;
        string T = S;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = i; j <= n; ++j)
            {
                string tmp1 = "";
                S.erase(i, j);
                for (int i = 1; i <= S.size(); ++i)
                {
                    tmp1 += S[i];
                }
                cout << tmp1 << '\n';
                if (tmp1 == "2020")
                {
                    check = 1;
                }
                S = T;
            }
        }
        if (check)
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }
}