#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
#define ll long long
#define nmax 10000000
#define oo 1000000000
ll n;
ll dem = 0;
ll ma = -oo;
ll m[1005];
string S;
void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
int main()
{
    FAST();
    freopen("B.inp", "r", stdin);
    freopen("B.out", "w", stdout);
    cin >> S;
    n = S.size();
    S = ' ' + S;
    for (int i = 1; i <= n; i++)
    {
        dem = 0;
        for (char j = 'a'; j <= 'z'; ++j)
            m[j - 'a' + 1] = 0;
        for (int j = i; j <= n; j++)
        {
            if (m[S[j] - 'a' + 1] == 0)
            {
                dem++;
                m[S[j] - 'a' + 1] = 1;
            }
            else
                break;
        }
        ma = max(ma, dem);
    }
    cout << ma;
}