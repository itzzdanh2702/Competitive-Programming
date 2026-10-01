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

int n, m;
ll HashS[MAXN];
ll HashT[MAXN];
ll p[MAXN], p1[MAXN];
string S, T;

ll getHash(int l, int r)
{
    return ((HashS[r] - HashS[l - 1] * p[r - l + 1]) % MOD + MOD) % MOD;
}

int main()
{
    FAST();
    cin >> S;
    cin >> T;
    n = S.size();
    m = T.size();
    S = " " + S;
    T = " " + T;
    HashS[0] = 0;
    HashT[0] = 0;
    for (int i = 1; i <= m; ++i)
    {
        HashT[i] = (HashT[i - 1] * base + (T[i] - 'a' + 1)) % MOD;
    }
    for (int i = 1; i <= n; ++i)
    {
        HashS[i] = (HashS[i - 1] * base + (S[i] - 'a' + 1)) % MOD;
    }
    p[0] = 1;
    for (int i = 1; i <= max(m, n); ++i)
    {
        p[i] = (p[i - 1] * base) % MOD;
    }
    int pos = 0;
    int cnt = 0;
    for (int i = n; i >= 1; --i)
    {
        ++cnt;
        //   cout << cnt << ' ' << i << '\n';
        if (getHash(i, n) == HashT[cnt])
        {
            pos = cnt;
        }
    }

    cout << S;
    for (int i = pos + 1; i <= m; ++i)
    {
        cout << T[i];
    }
}

// abc a