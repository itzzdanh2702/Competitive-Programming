#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nmax 1000000
#define pii pair<int, int>
#define fi first
#define se second

const ll INF = 1e9;

bool visited[nmax];
ll d[nmax];
int m, n, s, t, val;
int TC;
ll ma = -INF;
vector<pii> vec[nmax], ans;

void FAST()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void dijiktra(int u)
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    for (int i = 1; i <= n; i++)
        d[i] = INF;
    pq.push({0, u});
    d[u] = 0;
    while (!pq.empty())
    {
        pii top = pq.top();
        pq.pop();
        int valu = top.fi;
        int u = top.se;
        if (top.fi != d[u])
            continue;
        for (auto x : vec[u])
        {
            int v = x.fi;
            int valv = x.se;
            if (d[v] > d[u] + valv)
            {
                d[v] = d[u] + valv;
                pq.push({d[v], v});
            }
        }
    }
}
int main()
{
    FAST();
    cin >> n >> m;
    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        vec[v].push_back({u, w});
    }
    cin >> TC >> val;
    dijiktra(val);
    for (int i = 1; i <= TC; i++)
    {
        int u;
        cin >> u;
        ma = max(ma, d[u]);
        ans.push_back({d[u], u});
    }
    cout<<ma<<endl;
    sort(ans.begin(), ans.end());
    for (auto x : ans)
    {
        cout << x.se << ' ';
    }
}