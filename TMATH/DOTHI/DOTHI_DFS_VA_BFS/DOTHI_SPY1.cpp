#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll, ll>
#define fi first
#define se second
ll m, n, x, y, s, t, p, q;
ll dx[] = {0, -1, 1, 0};
ll dy[] = {1, 0, 0, -1};
bool visited[1001][1001];
char a[] = {'E', 'N', 'S', 'W'};
string kq[1001][1001][4], mi;
struct tom
{
    ll hang, cot, huong;
};
void bfs(ll x, ll y)
{
    queue<tom> qu;
    for (int i = 0; i < 4; i++)
        qu.push({x, y, i});

    while (!qu.empty())
    {
        tom top = qu.front();
        qu.pop();
        if ((top.hang == s) and (top.cot == t))
        {
            for (int i = 0; i < 4; i++)
            {
                cout << kq[top.hang][top.cot][i] << ' ';
            }
            exit(0);
        }
        for (int k = 0; k < 4; k++)
        {
            ll i1 = top.hang + dx[k];
            ll j1 = top.cot + dy[k];
            if ((i1 >= 0) and (i1 <= m) and (j1 >= 0) and (j1 <= n))
            {
                if ((!visited[i1][j1]) and (kq[i1][j1][k] == ""))
                {
                    if (a[k] != a[top.huong])
                    {
                        kq[i1][j1][k] = kq[top.hang][top.cot][top.huong] + a[k];
                        qu.push({i1, j1, k});
                    }
                }
            }
        }
    }
}
int main()
{
    memset(visited, false, sizeof(visited));
    cin >> m >> n >> x >> y >> s >> t;
    while (cin >> p >> q)
    {
        visited[p][q] = true;
    }
    bfs(x, y);
    cout << mi;
}