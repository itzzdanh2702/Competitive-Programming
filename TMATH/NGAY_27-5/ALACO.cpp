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
int dem1 = 0, dem2 = 0;
int n;
int main()
{
    FAST();
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        if (i % 3 == 0)
        {
            ++dem1;
        }
        else
        {
            ++dem2;
        }
    }
    cout << dem1 << '\n'<< dem2;
}