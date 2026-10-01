#include<iostream>
#include<vector>
using namespace std;
const int N = 405;
const int M = 1e5+5;
int d[N][N];
int n,m;
int a[M];
long long res = 0;
struct qr
{
    int f,c,r;
};
vector<qr> v[N];
namespace sub1
{
int s,f,c,r;
bool check (int mid)
{
    int res = 0;
    int st = s;
    for (int i=s; i<=f; i++)
    {
        int j = i;
        while (j < f && a[j+1]-a[i] <= mid)
        {
            j++;
        }
        if (j == i) return false;
        i = j-1;
        res++;
        if (j == f) break;
    }
    res--;
    return res <= r;
}
void solve ()
{
    for (int i=1; i<=n; i++) cin >> a[i];
    cin >> s >> f >> c >> r;
    long long lef = 0, rig = 1e9, res = 1e9;
    while (rig >= lef)
    {
        int mid = (rig+lef) >> 1;
        if (check(mid)) res = mid, rig = mid - 1;
        else lef = mid + 1;
    }
    cout << 1ll*res*c << '\n';
}
}
void cal ()
{
    for (int l=1; l<=n; l++)
    {
        for (int r=l; r<=n; r++)
        {
            d[r][0] = a[r] - a[l];
        }
        for (int k=1; k<=n; k++)
        {
            int opt = l;
            for (int r=l; r<=n; r++)
            {
                while (opt < r && max (d[opt][k-1],a[r]-a[opt]) >= max (d[opt+1][k-1],a[r]-a[opt+1]))
                {
                    opt++;
                }
                d[r][k] = max (d[opt][k-1],a[r]-a[opt]);
            }
        }
        for (auto val : v[l])
        {
            int f = val.f, c = val.c, r = val.r;
            res = max (res,1ll*d[f][r]*c);
        }
    }
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    if (m == 1)
    {
        sub1::solve();
        return 0;
    }
    for (int i=1; i<=n; i++)
    {
        cin >> a[i];
    }
    for (int i=1; i<=m; i++)
    {
        int s,f,c,r;
        cin >> s >> f >> c >> r;
        v[s].push_back({f,c,r});
    }
    cal();
    cout << res;
}
