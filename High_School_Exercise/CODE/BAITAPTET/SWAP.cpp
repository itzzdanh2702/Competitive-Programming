#include <bits/stdc++.h>
using namespace std;
#define ll long long
const long long MOD = 1000000007;
#define MAXN 1000005
#define oo 1000000000
void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
bool check = 0;
ll n;
int main()
{
    // freopen("SWAP.inp", "r", stdin);
    // freopen("SWAP.out", "w", stdout);
    FAST();
    cin >> n;
    while (n--)
    {
        string S, Q;
        cin >> S;
        Q = S;
        sort(Q.begin(), Q.end());
        for (int i = 0; i < S.size(); ++i)
        {
            if (S[i] < S[S.size() - i - 1])
            {
                swap(S[i], S[S.size() - i - 1]);
            }
        }
        if (S == Q)
        {
            cout << "1" << ' ';
        }
        else
        {
            cout << "0" << ' ';
        }
    }
}
