#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define pii pair<ll, ll>
const long long MOD = 1000000007;
#define MAXN 1000005
#define oo 100000000000
void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int TC;
int a[MAXN], b[MAXN];
int n;

int find_pos(int x[], int n, int k)
{
    int pos;
    ll mi = oo;
    for (int i = 1; i <= n; ++i)
    {
        if (abs(x[i] - k) < mi)
        {
            mi = abs(x[i] - k);
            pos = i;
        }
    }
    return pos;
}

int main()
{
    FAST();
    cin >> TC;
    while (TC--)
    {
        ll kq = 0;
        ll res = oo;
        cin >> n;
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i];
        }
        for (int i = 1; i <= n; ++i)
        {
            cin >> b[i];
        }
        int tmp1 = find_pos(b, n, a[1]);
        int tmp2 = find_pos(b, n, a[n]);
        int tmp3 = find_pos(a, n, b[1]);
        int tmp4 = find_pos(a, n, b[n]);
        //cout << tmp1 << ' ' << tmp2;
        vector<int> v1 = {1, tmp1, n};
        vector<int> v2 = {1, tmp2, n};
        for (int x : v1)
        {
            for (int y : v2)
            { 
                kq = abs(a[1] - b[x]) + abs(a[n] - b[y]);
                if ((x > 1) and (y > 1))
                {   
                    kq += abs(b[1] - a[tmp3]);
                }
                if ((x < n) and (y < n))
                {
                    kq += abs(b[n] - a[tmp4]);
                }
                res = min(res, kq);
            }
        }
        cout << res << '\n';
    }
}
