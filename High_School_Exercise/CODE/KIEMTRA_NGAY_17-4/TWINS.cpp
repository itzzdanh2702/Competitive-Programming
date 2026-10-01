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

bool nt[MAXN];
int n, k;
int dem = 0;

int main()
{
    freopen("TWINS.inp","r",stdin);
    freopen("TWINS.out","w",stdout);
    FAST();
    cin >> n >> k;
    memset(nt, true, sizeof(nt));
    nt[0] = nt[1] = false;
    for (int i = 2; i <= sqrt(MAXN); ++i)
    {
        if (nt[i])
        {
            for (int j = i * i; j <= MAXN; j += i)
            {
                nt[j] = false;
            }
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        if (i + k <= n)
        {
            if ((nt[i]) and (nt[i + k]))
            {
                ++dem;
            }
        }
    }
    cout << dem;
}