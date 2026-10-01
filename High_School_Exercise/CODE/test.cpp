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
        bool check[51][51];
        char ch, a[51][51];
        int cnt = 0, fr[51], num, ma = -oo;
        memset(check, false, sizeof(check));
        string S;
        cin >> S;
        S = " " + S;
        for (int i = 1; i <= S.size(); ++i)
        {
            a[1][i] = S[i];
            if (a[1][i] == 'Y')
                check[1][i] = 1;
        }
        for (int i = 2; i <= S.size() - 1; ++i)
        {
            for (int j = 1; j <= S.size() - 1; ++j)
            {
                cin >> a[i][j];
                if (a[i][j] == 'Y')
                {
                    check[i][j] = 1;
                }
            }
        }
        for(int i = 1 ; i <= S.size() - 1 ; ++i)
        {
            for(int j = 1 ; j <= S.size() - 1 ; ++j)
            {
                cout << a[i][j] << ' ';
            }
            cout << '\n';
        }
    }
}
