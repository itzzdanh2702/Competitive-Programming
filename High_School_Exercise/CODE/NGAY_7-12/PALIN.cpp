#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nmax 1000000
string S, P;

int main()
{
    freopen("PALIN.inp", "r", stdin);
    freopen("PALIN.out", "w", stdout);
    getline(cin, S);
    for (int i = S.size() - 1; i >= 0; i--)
    {
        P += S[i];
    }
    if (P == S)
        cout << "1";
    else
        cout << "0";
}