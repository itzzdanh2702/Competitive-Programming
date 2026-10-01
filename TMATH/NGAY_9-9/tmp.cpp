#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second

const int MAXN = 1e6 + 5;
const int base = 31;
const ll MOD = 1e9 + 7;

using namespace std;

string S;
ll p[MAXN];
ll HashS[MAXN];
int n, ans;

ll getHash(int l, int r)
{
    return ((HashS[r] - HashS[l - 1] * p[r - l + 1]) % MOD + MOD) % MOD;
}

int main()
{
    // freopen("tongnn.inp","r",stdin);
    // freopen("tongnn.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> S;
    n = S.size(); 
    S = " " + S;
    p[0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        p[i] = (p[i - 1] * base) % MOD;
    }
    for (int i = 1; i <= n; ++i)
    {
        HashS[i] = HashS[i - 1] * base + S[i] - 'a' + 1;
        HashS[i] %= MOD;
    }
    for (int i = 1; i <= n; ++i)
    {
        bool ok = 1;
        ll l = 1, r = i;
        while (HashS[i] == getHash(l, r))
        {
            l += i;
            r += i;
            if (HashS[i] != getHash(l, r))
            {
                if (r > n)
                {
                    if (getHash(l, n) != HashS[n - l + 1])
                    {
                        ok = 0;
                        break;
                    }
                }
                else 
                {
                    ok = 0;
                    break; 
                }
            }
        }
        if (ok)
        {
            cout << i << ' ';
        }
    }
}