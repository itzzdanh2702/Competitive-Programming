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
string tmp;
int pos;

int main()
{
    FAST();
    getline(cin, S);
    for (int i = 0; i < S.size(); ++i)
    {
        if (int(S[i]) == 95)
        {
            pos = i;
            break;
        }
    }
    for (int i = 0; i < pos - 1; ++i)
    {
        tmp += S[i];
    }

    if ((tmp == "We") || (tmp == "They") || (tmp == "You"))
    {
        cout << "are";
        return 0;
    }
    else if (tmp == "I")
    {
        cout << "am";
        return 0;
    }
    else
    {
        cout << "is";
        return 0;
    }
}