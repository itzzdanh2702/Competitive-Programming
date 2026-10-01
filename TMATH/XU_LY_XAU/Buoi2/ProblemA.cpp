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
int cnt = 0;
string tmp = " ";
int main()
{
    FAST();
    cin >> S;
    cout << "Ngay";
    for (int i = 0; i < S.size(); ++i)
    {
        if (S[i] != '/')
            tmp += S[i];
        if (S[i] == '/')
        {
            ++cnt;
            if (cnt == 1)
            {
                cout << tmp << ' ' << "thang" << ' ';
                tmp = "";
            }
            else if (cnt == 2)
            {
                cout << tmp << ' ' << "nam" << ' ';
                tmp = "";
            }
        }
    }
    cout << tmp;
}