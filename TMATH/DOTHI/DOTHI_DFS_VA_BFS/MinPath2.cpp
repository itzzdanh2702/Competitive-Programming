#include <bits/stdc++.h>
using namespace std;
#define ll long long
const long long MOD = 1000000007;
#define MAXN 1000005
#define oo 1000000000
#define pii pair<int, int>
#define fi first
#define se second

void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int n, m, s, t;
bool visited[1][MAXN];
vector<int> vec[MAXN];

void bfs(int u)
{
    queue<pii> qu;
    qu.push({0, u});
    while (!qu.empty())
    {
        pii top = qu.front();
        qu.pop();
        if ((top.se == t) and (top.fi % 2 == 0))
        {
            cout << top.fi;
            exit(0);
        }
        for (auto x : vec[top.se])
        {
            if (!visited[(top.fi + 1) % 2][x])
            {
                visited[(top.fi + 1) % 2][x] = true;
                qu.push({top.fi + 1, x});
            }
        }
    }
}
int main()
{
    cin >> n >> m >> s >> t;
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    bfs(s);
}