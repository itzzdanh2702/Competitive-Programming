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
string S;
int main()
{
    FAST();
    // freopen("RIMSKI.INP", "r", stdin);
    // freopen("RIMSKI.OUT", "w", stdout);
    cin >> S;
    for (int i = 0; i < S.size(); ++i)
    {
        if ((S[i] == 'V') and (S[i + 1] == 'I') and (S[i + 2] != 'I'))
        {
            swap(S[i], S[i + 1]);
        }
        if ((S[i] == 'X') and (S[i + 1] == 'I') and (S[i + 2] != 'I') and (S[i + 2] != 'X') and (S[i + 2] != 'V'))
        {
            swap(S[i], S[i + 1]);
        }
        if ((S[i] == 'L') and (S[i + 1] == 'X') and (S[i + 2] != 'X'))
        {
            swap(S[i], S[i + 1]);
        }
    }
    cout << S;
}