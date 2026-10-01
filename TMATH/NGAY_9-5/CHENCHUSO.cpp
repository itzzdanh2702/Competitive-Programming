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
int c;
string Q;
bool check = 0;
int main()
{
    FAST();
    freopen("insdig.inp", "r", stdin);
    freopen("insdig.out", "w", stdout);
    cin >> S >> c;
    for (int i = 0; i < S.size(); ++i)
    {
        if ((int(S[i] - 48) < c) && (check == 0))
        {
            Q = Q + to_string(c) + S[i];
            check = 1;
        }
        else
        {
            Q += S[i];
        }
    }
    if (check == 0)
    {
        Q += to_string(c);
        cout << Q;
    }
    else
    {
        cout << Q;
    }
}
