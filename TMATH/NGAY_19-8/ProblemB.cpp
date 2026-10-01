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
ll sum = 0;
bool check = 0;

int main(int argc, char const *argv[])
{
    cin >> S;
    for (int i = 0; i < S.size(); ++i)
    {
        sum += int(S[i] - 48);
        if (S[i] == '0')
        {
            check = 1;
        }
    }
    if ((sum % 3 == 0) && (check == 1))
    {
        sort(S.begin(),S.end());
        reverse(S.begin(),S.end()); 
        for(int i = 0 ; i < S.size() ; ++i)
        {
            cout << S[i];
        }
    }
    else 
    {   
        cout << "-1";
    }
    return 0;
}
