#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nmax 1000000
string S;
ll sum;
int main()
{
    freopen("SUMDIGIT.inp","r",stdin);
    freopen("SUMDIGIT.out","w",stdout);
    getline(cin, S);
    for (int i = 0; i < S.size(); i++)
    {
        sum += int(S[i] - 48);
    }
    cout << S.size() << ' ' << sum;
}