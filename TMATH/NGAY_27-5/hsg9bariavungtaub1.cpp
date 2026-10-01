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

int n;
int a[MAXN];
int b[MAXN];
vector<pii> v1[MAXN];
int mp1[MAXN], mp2[MAXN];
int ma = 1;
ll store[1001][31];
void solve(int k)
{
    int tmp = k;
    for (int i = 2; i <= sqrt(tmp); ++i)
    {
        int dem = 0;
        if (tmp % i == 0)
        {
            while (tmp % i == 0)
            {
                ++dem;
                tmp /= i;
            }
            v1[k].push_back({i, dem});
        }
    }
    if (tmp > 1)
        v1[k].push_back({tmp, 1});
}
int main()
{
    FAST();
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        b[i] = a[i];
        solve(a[i]);
    }
    for (int i = 1; i <= 1000; ++i)
    {
        store[i][0] = 1;
    }
    for (int i = 1; i <= 1000; ++i)
    {
        for (int j = 1; j <= 21; ++j)
        {
            if (i * store[i][j - 1] <= 1000000)
            {
                store[i][j] = store[i][j - 1] * i;
            }
            else
            {
                break;
            }
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        int si = v1[a[i]].size();
        if (mp2[a[i]] != 0)
        {
            ma = max(ma, a[i]);
            continue;
        }
        ++mp2[a[i]];
        if (a[i] == 1)
        {
            continue;
        }
        for (int q = 0; q <= v1[a[i]][0].se; ++q)
        {
            if (si < 1)
                break;
            int tmp = store[v1[a[i]][0].fi][q];
            if (tmp > b[i])
                break;
            if (mp1[tmp] != 0)
            {
                ma = max(ma, tmp);
            }
            ++mp1[tmp];
            for (int j = 0; j <= v1[a[i]][1].se; ++j)
            {
                if (si < 2)
                    break;
                int tmp1 = tmp * store[v1[a[i]][1].fi][j];
                if (tmp1 > b[i])
                    break;
                if (mp1[tmp1] != 0)
                {
                    ma = max(ma, tmp1);
                }
                ++mp1[tmp1];
                for (int k = 0; k <= v1[a[i]][2].se; ++k)
                {
                    if (si < 3)
                        break;
                    int tmp2 = tmp1 * store[v1[a[i]][2].fi][k];
                    if (tmp2 > b[i])
                        break;
                    if (mp1[tmp2] != 0)
                        ma = max(ma, tmp2);
                    ++mp1[tmp2];
                    for (int l = 0; l <= v1[a[i]][3].se; ++l)
                    {
                        if (si < 4)
                            break;
                        int tmp3 = tmp2 * store[v1[a[i]][3].fi][l];
                        if (tmp3 > b[i])
                            break;
                        if (mp1[tmp3] != 0)
                            ma = max(ma, tmp3);
                        ++mp1[tmp3];
                        for (int m = 0; m <= v1[a[i]][4].se; ++m)
                        {
                            if (si < 5)
                                break;
                            int tmp4 = tmp3 * store[v1[a[i]][4].fi][m];
                            if (tmp4 > b[i])
                                break;
                            if (mp1[tmp4] != 0)
                            {
                                ma = max(ma, tmp4);
                            }
                            ++mp1[tmp4];
                            for (int g = 0; g <= v1[a[i]][5].se; ++g)
                            {
                                if (si < 6)
                                    break;
                                int tmp5 = tmp4 * store[v1[a[i]][5].fi][g];
                                if (tmp5 > b[i])
                                    break;
                                if (mp1[tmp5] != 0)
                                    ma = max(ma, tmp5);
                                ++mp1[tmp5];
                                for (int g1 = 0; g1 <= v1[a[i]][6].se; ++g1)
                                {
                                    if (si < 7)
                                        break;
                                    int tmp6 = tmp5 * store[v1[a[i]][6].fi][g1];
                                    if (tmp6 > b[i])
                                        break;
                                    if (mp1[tmp6] != 0)
                                        ma = max(ma, tmp6);
                                    ++mp1[tmp6];
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout << ma;
}