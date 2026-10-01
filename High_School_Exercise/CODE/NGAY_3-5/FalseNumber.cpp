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
int pos = 0;
string S;

int main()
{
    // freopen("FalseNumber.inp","r",stdin);
    // freopen("FalseNumber.out","w",stdout);
    FAST();
    cin >> TC;
    while (TC--)
    {
        string ans;
        int pos = 0;
        cin >> S;
        if (S[0] != '1')
        {
            ans = "1" + S;
            cout << ans << '\n';
            continue;
        }

        for (int i = 1; i < S.size(); ++i)
        {
            if (S[i] != '0')
            {
                pos = i;
                break;
            }
        }

        for (int i = 0; i < S.size(); ++i)
        {
            if (i == pos)
            {
                ans += "0";
                ans += S[i];
            }
            else
            {
                ans += S[i];
            }
        }
        cout << ans << '\n';
    }
}