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

string S, P;
string tmp;
ll dem = 0;
int main()
{
    FAST();
    freopen("pointmut.inp", "r", stdin);
    freopen("pointmut.out", "w", stdout);
    cin >> S >> P;
    for (int i = 1; i <= S.size() / 3; ++i)
    {
        tmp += P;
    }
    for (int i = 0; i < S.size(); ++i)
    {
        if (S[i] != tmp[i])
        {
            ++dem;
        }
    }
    cout << dem;
}