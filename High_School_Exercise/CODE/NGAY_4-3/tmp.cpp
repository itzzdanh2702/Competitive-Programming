#include <bits/stdc++.h>
using namespace std;

#define int long long
#define forn(i, n) for (int i = 0; i < n; i++)
#define um unordered_map
#define us unordered_set
#define sz(v) (int)v.size()
#define all(x) x.begin(), x.end()
#define pb push_back
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define pii pair<int, int>
#define fi first
#define se second

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;

const ll md = 1000000007;
const ll inf = LLONG_MAX;

// Graph Grid //
int dirs[] = {0, 1, 0, -1, 0};
int dirx[8] = {-1, 0, 0, 1, -1, -1, 1, 1};
int diry[8] = {0, 1, -1, 0, -1, 1, -1, 1};

vector<int> fac(2e3 + 20);
int N = 2e3 + 20;
int p = 998244353;

unsigned long long power(unsigned long long x,int y, int p)
{
    unsigned long long res = 1; // Initialize result

    x = x % p; // Update x if it is more than or
    // equal to p

    while (y > 0)
    {

        // If y is odd, multiply x with result
        if (y & 1)
            res = (res * x) % p;

        // y must be even now
        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}

// Returns n^(-1) mod p
unsigned long long modInverse(unsigned long long n,
                              int p)
{
    return power(n, p - 2, p);
}

int ncrModP(int n, int r)
{
    if (n < r)
        return 0;
    // Base case
    if (r == 0)
        return 1;

    return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) % p;
}

void solve()
{
    // MY APPROACH

    int n, m;
    cin >> n >> m;

    int validPathLength = n + m - 1;
    if (((validPathLength) & (1)))
    {
        cout << 0 << '\n';
        return;
    }

    int numPaths = ncrModP(validPathLength - 1, min(n - 1, m - 1));
    int remainingCells = n * m - validPathLength;
    int ans = ncrModP(validPathLength, validPathLength / 2) % p * numPaths % p * power(2LL, remainingCells, p) % p;

    ans = (ans) % p;
    cout << ans << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // MY APPROACH

    fac[0] = 1;
    for (int i = 1; i <= N; i++)
        fac[i] = (fac[i - 1] * i) % p;

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}