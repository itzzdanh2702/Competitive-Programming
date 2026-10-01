#include <bits/stdc++.h>
using namespace std;
#define nmax 1000000
#define ll long long
vector<ll> dinhke[nmax];
bool visited[nmax];
ll n, m;
ll d[nmax];

int main()
{
    //freopen("div.inp", "r", stdin);
    //freopen("div.out", "w", stdout);
    cin >> n >> m;
    while (m--)
    {
        ll u, v;
        cin >> u >> v;
        dinhke[u].push_back(v);
        dinhke[v].push_back(u);
    }
    queue<ll> qu;
    for(int i=1;i<=n;i++)
    {
    if(d[i]) continue;
    d[i] = 1;
    qu.push(i);
    while (!qu.empty())
    {
        ll tmp = qu.front();
        qu.pop();
        for (auto x : dinhke[tmp])
        {
            if (d[x] == d[tmp])
                return cout << "-1", 0;
            if (!d[x])
            {
                if (d[tmp] == 1)
                    d[x] = 2;
                else
                    d[x] = 1;
                qu.push(x);
            }
        }
    }
    }
    for (int i = 1; i <= n; i++)
        cout << d[i] << ' ';
}