#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
#define MAXN 1000005
void FAST()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int nx, ny;
int a[1005][1005];
int X[1005][1005];
pair<int, int> x, y;
queue<pair<int, int>> Q;
bool check[2005][2005];
int main()
{
	FAST();
	cin >> nx >> ny >> x.first >> x.second >> y.first >> y.second;
	for (int i = 1; i <= nx; i++)
	{
		for (int j = 1; j <= nx; j++)
			X[i][j] = -1;
	}

	for (int i = 1; i <= ny; i++)
	{
		int u, v;
		cin >> u >> v;
		a[u][v] = 1;
		check[u][v] = 1;
	}

	Q.push({x.first, x.second});
	X[x.first][x.second] = 0;

	while (!Q.empty())
	{
		auto top = Q.front();
		Q.pop();

		int u = top.first;
		int v = top.second;

		for (int i = v + 1; i <= nx; i++)
		{
			if (a[u][i])
				break;
			if (X[u][i] == -1)
			{
				X[u][i] = X[u][v] + 1;
				Q.push({u, i});
			}
		}

		for (int i = v - 1; i >= 1; i--)
		{
			if (a[u][i])
				break;
			if (X[u][i] == -1)
			{
				X[u][i] = X[u][v] + 1;
				Q.push({u, i});
			}
		}

		for (int i = u + 1; i <= nx; i++)
		{
			if (a[i][v])
				break;
			if (X[i][v] == -1)
			{
				X[i][v] = X[u][v] + 1;
				Q.push({i, v});
			}
		}

		for (int i = u - 1; i >= 1; i--)
		{
			if (a[i][v])
				break;
			if (X[i][v] == -1)
			{
				X[i][v] = X[u][v] + 1;
				Q.push({i, v});
			}
		}
	}
	cout << X[y.first][y.second];
}
