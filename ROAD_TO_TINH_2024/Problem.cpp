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

bool check[MAXN];
int h[MAXN], max_gap[MAXN] = {-oo}, min_gap[MAXN] = {oo}, n, m, s, t;
vector<int> adj[MAXN];

void bfs(int p)
{
    queue<int> qu;
    qu.push(p);
    while (!qu.empty())
    {
        int node = qu.front();
        qu.pop();
        check[node] = 1;
        cout << node << ':' << ' ';
        for (auto new_node : adj[node])
        {
            if (!check[new_node])
            {
                cout << new_node << ' ';
                max_gap[new_node] = max(max_gap[node], abs(h[new_node] - h[node]));
                min_gap[new_node] = min(min_gap[new_node],max_gap[new_node]);
                if(new_node == t)
                    max_gap[new_node] = -oo; 
                qu.push(new_node);
            }
        }
        cout << '\n'; 
    }
    // if (!check[t])
    //     return false;
}
int main()
{
    FAST();
    cin >> n >> m >> s >> t;
    for (int i = 1; i <= n; ++i)
    {
        cin >> h[i];
    }
    for (int i = 1; i <= m; ++i)
    {
        int p, k;
        cin >> p >> k;
        adj[p].push_back(k);
        adj[k].push_back(p);
    }
    // if (bfs(s))
    //     cout << min_gap[t];
    // else
    //     cout << "-1";
    bfs(s);
}