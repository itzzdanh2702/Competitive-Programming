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

ll TC;
ll a, b;
string S;

int main()
{
    FAST();
    cin >> TC;
    while (TC--)
    {
        ll kq = 0;
        ll dem = oo;
        cin >> a >> b;
        cin >> S;
        for(int i = 0 ; i < S.size() ; ++i)
        {
            if(S[i] == '1')
            {
                kq += min(a,dem * b);
                dem = 0;
            }
            else 
            {
                ++dem;
            }
        }
        cout << kq << '\n';
    }
}
