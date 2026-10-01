#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second

const int MAXN = 1e6 + 5;
const int base = 1e4 + 7;
const ll MOD = 1e9 + 7;

using namespace std;

ll p[MAXN];
ll HashA[MAXN];
int n, ans;
int a[MAXN];

ll getHash(int l,int r)
{
    return ((HashA[r] - HashA[l - 1] * p[r - l + 1]) % MOD + MOD) % MOD;
}

int main()
{
    //freopen("tongnn.inp","r",stdin);
    //freopen("tongnn.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 1 ; i <= n ; ++i)
    {
        cin >> a[i];
    }
    p[0] = 1;
    for(int i = 1 ; i <= n ; ++i)
    {
        p[i] = (p[i - 1] * base) % MOD;
    }
    for (int i = 1 ; i <= n ; ++i)
    {
        HashA[i] = HashA[i - 1] * base + a[i];
        HashA[i] %= MOD;
    }
    for(int i = 1 ; i <= n ; ++i)
    {
        bool ok = 1;
        ll l = 1,r = i;
        while(HashA[i] == getHash(l,r))
        {
            l += i;
            r += i;
            if(r + i - 1 > n)
            {
                break; 
            }
            if(HashA[i] != getHash(l,r))
            {
                ok = 0;
                break;
            }
        }
        int tmp = n % i;
        if(ok)
        {
            if(getHash(n - tmp + 1,n) != HashA[tmp])
            {
                continue;
            }
        }
        else
        {
            continue;
        }
        if(ok)
        {
            cout << i << ' ';
            return 0; 
        }
    }
}