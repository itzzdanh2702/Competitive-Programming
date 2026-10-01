#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define pii pair<ll, ll>
const long long MOD = 1000000007;
#define MAXN 5 * 1000005
#define oo 1000000000
void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int n;
int a[MAXN], pos1[MAXN], pos2[MAXN], pos3[MAXN], ans[MAXN], tmp[MAXN];
bool check[MAXN];
int mi = oo;

int main(int argc, char const *argv[])
{
    freopen("cophieu.inp","r",stdin);
    freopen("cophieu.out","w",stdout);
    FAST();
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        tmp[i] = a[i];
        if (a[i] <= mi)
        {
            mi = a[i];
        }
        else
        {
            if (pos1[a[i]] == 0)
                pos1[a[i]] = i;
        }
        if (pos2[a[i]] == 0)
            pos2[a[i]] = i;
    }
    mi = oo;
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i)
    {
        if(a[i] == a[i - 1])
            continue;
        if (pos1[a[i]] == 0)
            ans[a[i]] = 0;
        else
        {
            ans[a[i]] = pos1[a[i]] - mi;
        }
        mi = min(mi, pos2[a[i]]);
    }
    mi = oo;
    for (int i = 1; i <= n; ++i)
    {
        if (tmp[i] > mi)
        {
            if (check[tmp[i]] == 0)
            {
                cout << ans[tmp[i]] << ' ';
                pos3[tmp[i]] = i;
                check[tmp[i]] = 1;
            }
            else
            {
                cout << ans[tmp[i]] + i - pos3[tmp[i]] << ' ';
                ans[tmp[i]] = ans[tmp[i]] + i - pos3[tmp[i]];
                pos3[tmp[i]] = i;
            }
        }
        else
        {
            cout << 0 << ' ';
            mi = tmp[i];
        }
    }
}
