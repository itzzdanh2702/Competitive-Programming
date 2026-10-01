#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nmax 1000000
ll m, n, p, q;

vector<ll> dinhke[100005];
bool visited[100005];
bool bfs(int k)
{
    queue<ll> qu;
    qu.push(k);
    visited[k] = true;
    if (k == q)
        return true;
    while (!qu.empty())
    {
        ll tmp = qu.front();
        qu.pop();
        for (auto x : dinhke[tmp])
        {
            if (!visited[x])
            {
                visited[x] = true;
                if (x == q)
                    return true;
                qu.push(x);
            }
        }
    }
    return false;
}
int main()
{
    cin >> m >> n;
    while (n--)
    {
        ll u, v;
        cin >> u >> v;
        dinhke[u].push_back(v);
    }
    cin >> p >> q;
    if (bfs(p))
        cout << "Yes";
    else
        cout << "No";
}