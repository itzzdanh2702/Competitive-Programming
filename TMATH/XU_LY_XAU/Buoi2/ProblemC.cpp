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

int n;
string S;

int main()
{
    FAST();
    cin >> n;
    while (n--)
    {
        int pos;
        cin >> S;
        cout << S[0];
        for (int i = 1; i < S.size(); ++i)
        {
            if (S[i] == '@')
            {
                pos = i;
            }
        }
        for(int i = 1 ; i < S.size() ; ++i)
        {
            if(i < pos - 1)
            {
                cout << '-';
            }
            else
            {
                cout << S[i];
            }
        }
        cout << '\n';
    }
}