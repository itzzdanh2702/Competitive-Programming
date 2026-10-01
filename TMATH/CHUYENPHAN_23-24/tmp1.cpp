#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const ll oo = 1e9;
int n, kq[11], d[11];
int b[11];
int cnt = 0;
int k;
ll ans[11];
ll ans1 = 1;
bool check[11];
int mi = oo;
pair<int, int> a[11];

void FAST()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
void xuat()
{
	memset(check, false, sizeof(check));
	int S = 0;
	int tmp1 = 0;
	for (int j = 1; j <= 2 * n; ++j)
	{
		int tmp = kq[j] / 2;
		if (kq[j] % 2 == 0)
		{
			if (check[kq[j] - 1])
			{
				S += abs(a[tmp].se - tmp1);
				tmp1 = a[tmp].se;
			}
			else
				return;
		}
		else
		{
			S += abs(a[tmp + 1].fi - tmp1);
			tmp1 = a[tmp + 1].fi;
			check[kq[j]] = 1;
		}
	}
	S += abs(k - tmp1);
	if (S == 237)
	{
		for (int i = 1; i <= 2 * n; ++i)
		{
			if (kq[i] & 1)
				cout << a[kq[i] / 2 + 1].fi << ' ';
			else
				cout << a[kq[i] / 2].se << ' ';
		}
		cout << '\n';
	}
	mi = min(mi, S);
}

void dequy(int i)
{
	for (int j = 1; j <= 2 * n; ++j)
		if (d[b[j]] > 0)
		{
			kq[i] = b[j];
			--d[b[j]];
			if (i < 2 * n)
				dequy(i + 1);
			else if (i == 2 * n)
			{
				xuat();
			}
			++d[b[j]];
		}
}

int main()
{
	FAST();
	cin >> n >> k;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i].fi >> a[i].se;
	}
	for (int i = 1; i <= 2 * n; ++i)
	{
		b[i] = i;
		d[b[i]] = 1;
	}
	dequy(1);
	cout << mi;
}
