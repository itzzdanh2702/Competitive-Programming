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

ll TC;

int main()
{
    FAST();
    freopen("MIN.inp", "r", stdin);
    freopen("MIN.out", "w", stdout);
    cin >> TC;
    while (TC--)
    {
        string S;
        cin >> S;
        if(S.size()==2)
        cout << S << endl;
        else 
        {
        sort(S.begin(), S.end());
        cout << S << endl;
        }
    }
}   