#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define MAXN 1000005

int n, x, y, a, b;
int X[MAXN];
vector<int> v[MAXN];
int main()
{
    cin >> n >> x >> y >> a >> b;

    for (int i = 1; i <= n; i++)
    {
        v[i].push_back(i + x);
        if (i > y)
            v[i].push_back(i - y);
    }

    queue<int> Q;
    Q.push(a);
    X[a] = 1;
    while (!Q.empty())
    {
        int res = Q.front();
        Q.pop();
        for (int xx : v[res])
        {
            if (X[xx])
                continue;
            X[xx] = X[res] + 1;
            Q.push(xx);
        }
    }

    if (!X[b])
        return cout << -1, 0;
    else
        cout << X[b] - 1;
}
