//** LaziChicken - 12/2022 **

#pragma GCC optimize ("O3")

#include <bits/stdc++.h>

using namespace std;

//---------- Define ------------
#define ll long long
#define ld long double
//------------------------------
#define pii pair <int, int>
#define pli pair <ll, int>
#define pil pair <int, ll>
#define pll pair <ll, ll>
#define fi first
#define se second
#define tupi tuple <int, int, int>
#define inf 0x3f3f3f3f
const ll nx = 1e6+9;
const ll bx = 4e6+9;
const ll kx = 1e3+9;
const ll mod = 1e9+7;

int n;
ll h[nx], a[nx], seg[nx<<2], ma = 0;
vector <int> vt;
unordered_map <int, int> mp;

void update(int l, int r, int pos, ll val, int id)
{
    if (l > pos or r < pos) return;
    if (l == r)
    {
        seg[id] = val;
        return;
    }
    int mid = (l + r) >> 1;
    update(l, mid, pos, val, id<<1);
    update(mid+1, r, pos, val, id<<1|1);
    seg[id] = max(seg[id<<1], seg[id<<1|1]);
} 

ll get(int l, int r, int u, int v, int id)
    {
    if (l > v or r < u) return LLONG_MIN;
    if (u <= l and r <= v) return seg[id];
    int mid = (l + r) >> 1;
    return max(get(l, mid, u, v, id<<1), get(mid+1, r, u, v, id<<1|1));
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> h[i];
        vt.emplace_back(h[i]);
    }
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(vt.begin(), vt.end());
    for (int i = 0; i < vt.size(); i++)
    {
        mp[vt[i]] = i + 1;
    }
    for (int i = 1; i <= n; i++)
    {
        ll tmp = get(1, n, 1, mp[h[i]], 1);
        ma = max(ma, tmp + a[i]);
        update(1, n, mp[h[i]], tmp+a[i], 1);
    }
    cout << ma;
}