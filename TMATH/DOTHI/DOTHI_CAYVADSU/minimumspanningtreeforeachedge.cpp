#include <bits/stdc++.h>

#define int long long
#define pii pair<int,int>

using namespace std;

struct Edge{
    int u, v, w, id;
    bool operator< (Edge const& other) const{
        return w < other.w;
    }
};

const int N = 2e5 + 5;
int n, m, sum;
int par[N], sz[N], res[N], up[N][18], val[N][18], d[N];
vector<Edge> edges;
vector<pii> g[N];

int find_set(int v) {
    return (v == par[v] ? v : par[v] = find_set(par[v]));
}

bool join_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);

    if (a == b) return 0;

    if (sz[a] < sz[b]) swap(a, b);
    par[b] = a;
    sz[a] += sz[b];
    return 1;
}

void dfs(int u, int p) {
    for (int i = 1; i <= 17; i++) {
        up[u][i] = up[up[u][i - 1]][i - 1];
        val[u][i] = max(val[u][i - 1], val[up[u][i - 1]][i - 1]);
    }

    for (auto e : g[u]) {
        int v = e.first, w = e.second;
        if (v == p) continue;
        up[v][0] = u;
        val[v][0] = w;
        d[v] = d[u] + 1;
        dfs(v, u);
    }
}

int get(int u, int v) {
    int res = 0;
    if (d[u] < d[v]) swap(u, v);
    for (int i = 17; i >= 0; i--) if (d[u] - d[v] >= (1 << i)) {
        res = max(res, val[u][i]);
        u = up[u][i];
    }
    if (u == v) return res;

    for (int i = 17; i >= 0; i--) if (up[u][i] != up[v][i]) {
        res = max({res, val[u][i], val[v][i]});
        u = up[u][i];
        v = up[v][i];
    }
    return max({res, val[u][0], val[v][0]});
}

signed main() {

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        par[i] = i;
        sz[i] = 1;
    }
    for (int i = 1, u, v, w; i <= m; i++) {
        cin >> u >> v >> w;
        edges.push_back({u, v, w, i});
    }

    sort(edges.begin(), edges.end());
    for (auto e : edges) if (join_sets(e.u, e.v)) {
        g[e.u].push_back({e.v, e.w});
        g[e.v].push_back({e.u, e.w});
        sum += e.w;
    }

    dfs(1, 0);
    for (auto e : edges) res[e.id] = sum - get(e.u, e.v) + e.w;

    for (int i = 1; i <= m; i++) cout << res[i] << "\n";

}
