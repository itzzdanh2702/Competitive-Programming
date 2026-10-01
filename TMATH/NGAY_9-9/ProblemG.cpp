#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define pii pair<ll, ll>
const long long MOD = 1000000007;
const int base = 31;
#define MAXN 1000005
#define oo 1000000000
void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int n;
int TC;
ll HashS[MAXN];
ll reverse_Hash[MAXN];
ll p[MAXN];
string S;

ll getHash(int l, int r)
{
    return ((HashS[r] - HashS[l - 1] * p[r - l + 1]) % MOD + MOD) % MOD;
}

ll getHash1(int l, int r)
{
    return ((reverse_Hash[l] - reverse_Hash[r + 1] * p[r - l + 1]) % MOD + MOD) % MOD;
}

int main()
{
    FAST();
    cin >> n;
    cin >> S;
    S = " " + S;
    HashS[0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        HashS[i] = (HashS[i - 1] * base + (S[i] - 'a' + 1)) % MOD;
    }
    p[0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        p[i] = (p[i - 1] * base) % MOD;
    }
    reverse_Hash[n + 1] = 0;
    for (int i = n; i >= 1; --i)
    {
        reverse_Hash[i] = (reverse_Hash[i + 1] * base + (S[i] - 'a' + 1)) % MOD;
    }
    cin >> TC;
    while (TC--)
    {
        int l, r;
        cin >> l >> r;
        if(getHash(l,r) == getHash1(l,r))
        {
            cout << "1" << '\n';
        }
        else 
        {
            cout << "0" << '\n';
        }

    }
}

// abc a