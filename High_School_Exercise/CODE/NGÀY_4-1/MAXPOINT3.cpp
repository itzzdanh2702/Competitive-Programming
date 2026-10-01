#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
#define MAXN 1000005
#define oo 1000000000
void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int st[MAXN];
int n, m;

void update(int id, int l, int r, int i, int v)
{
    if (i < l || r < i)
    {
        return;
    }
    if (l == r)
    {
        st[id] = v;
        return;
    }
    int mid = (l + r) / 2;
    update(id * 2, l, mid, i, v);
    update(id * 2 + 1, mid + 1, r, i, v);
    st[id] = max(st[id * 2], st[id * 2 + 1]);
}

int get(int id, int l, int r, int u, int v)
{
    if (v < l || r < u)
    {
        return -oo;
    }
    if (u <= l && r <= v)
    {

        return st[id];
    }
    int mid = (l + r) / 2;
    return max(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
}

int main()
{
    FAST();
    cin >> n >> m;
    build(1,1,n);
    for (int k = 1; k <= 2 * m; k++)
    {
        int v, i, j;
        cin >> v >> i >> j;
        if (v == 1)
        {
            update(1, 1, n, j, i);
        }
        else
        {
            cout << get(1, 1, n, i, j) << endl;
        }
    }
}
