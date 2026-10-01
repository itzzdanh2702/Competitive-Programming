#include <bits/stdc++.h>
using namespace std;
#define ll long long
const long long MOD = 1000000007;
#define MAXN 1000005
#define oo 1000000000
#define rs(x, a) memset(x, (a), sizeof x)
#define TASK ""
#define FILE(X)                     \
    freopen(#X ".INP", "r", stdin); \
    freopen(#X ".OUT", "w", stdout);

void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int n;
int a[MAXN];
int st[MAXN];
vector<int> X[MAXN];
int t;
int k;
ll x;

void build(int id, int l, int r)
{
    if (l == r)
    {
        st[id] = a[l];
        return;
    }
    int m = (l + r) / 2;
    build(id * 2, l, m);
    build(id * 2 + 1, m + 1, r);
    st[id] = max(st[2 * id], st[2 * id + 1]);
}

int main()
{
    freopen("BUILD.inp","r",stdin);
    freopen("BUILD.out","w",stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    build(1, 1, n);
    cin >> t;
    while (t--)
    {
        cin >> x;
        if (st[x] == 0)
        {
            cout << "-1" << endl;
        }
        else
        {
            cout << st[x] << ' ';
            if (st[2 * x] == 0)
                cout << "-1" << ' ';
            else
            {
                cout << st[2 * x] << ' ';
            }
            if (st[2 * x + 1] == 0)
                cout << "-1" << endl;
            else
                cout << st[2 * x + 1] << endl;
        }
    }
}
