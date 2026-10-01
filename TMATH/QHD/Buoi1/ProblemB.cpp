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

int TC;
int n;
unsigned ll f[MAXN];

int main()
{
    FAST();
    f[0] = f[1] = 1; 
    for(int i = 2 ; i <= 92 ; ++i)
    {
        f[i] = f[i - 1] + f[i - 2]; 
    }
    cin >> TC;
    while(TC--)
    {
        cin >> n;
        cout << f[n] << '\n';
    }
}