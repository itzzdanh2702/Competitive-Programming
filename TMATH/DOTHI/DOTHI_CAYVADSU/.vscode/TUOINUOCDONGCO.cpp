#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nmax 1000000
#define pii pair<ll, ll>
#define fi first
#define se second
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
ll n;
ll a[nmax];
ll b[1001][1001];
ll d[nmax];
ll ans;
priority_queue<pii, vector<pii>, greater<pii>> pq;
vector<pii> v[nmax];
bool visited[nmax];

void FAST()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void prim(int u)
{
    d[u] = 0;
    pq.push({d[u], u});
    while (!pq.empty())
    {
        pii node = pq.top();
        pq.pop();
        ll u = node.second;
        if (visited[u] == 1)
            continue;
        visited[u] = 1;
        ans += d[u];
        for (auto x : v[u])
        {
            int q = x.fi;
            int w = x.se;
            if (q < d[w])
            {
                d[w] = q;
                pq.push({d[w], w});
            }
        }
    }
}
int main()
{
    FAST();
    cin >> n;
    for (int i = 1; i <= n; i++)
        d[i] = INF;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        v[0].push_back({a[i], i});
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> b[i][j];
            if (i != j)
            {
                v[i].push_back({b[i][j], j});
               
            }
        }
    }
    prim(0);
    cout << ans;
}