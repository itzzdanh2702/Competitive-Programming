#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
#define MAXN 1000005
#define oo 1000000000
void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

string code[] = {"3027416859","0413852796"};
map<vector<int>,int> mp;
vector<int> xoay(vector<int> a,string code)
{
    vector<int> b(a);
    for (int i = 0; i < 9; ++i)
    {
        b[i] = a[code[i] - '0'];
    }
    return b;
}




