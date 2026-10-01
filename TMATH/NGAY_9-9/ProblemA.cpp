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

int n;
int BASE;
int TC;
ll store[MAXN];
ll ans = 0;
string S;

int main()
{
    FAST();
    cin >> BASE;
    cin >> S;
    for (int i = 0; i < S.size(); ++i)
    {
        ans = (ans * 31 + (S[i] - 'a' + 1)) % BASE;
    }
    cout << ans; 
}

// abc a