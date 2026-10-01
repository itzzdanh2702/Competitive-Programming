#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define sz(x) (int)x.size()
#define ii pair<ll, ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pf push_front
#define all(x) x.begin(), x.end()

using namespace std;

const int LOG = 20;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;
const int mxN = 3e5 + 66;

ll N, M;
multiset<ll> des;

void solve()
{
	cin >> N >> M;
	int left = 0;
	vector<ii> things(N);
	for (int i = 0; i < N; i++)
	{
		cin >> things[i].fi >> things[i].se;
		if (things[i].fi > things[i].se)
		{
			des.insert(things[i].se);
		}
	}

	sort(all(things));
	/*
	+des : [3,2];
	+things:
			5 2
			7 3
	des : [3];
	mi = 2;
	cnt = 1;

	*/
	ll ans = 0, mi = INF, cur = 0, cnt = 0;
	for (int i = 0; i < N; i++)
	{
		if (things[i].fi > things[i].se)
		{
			des.erase(des.find(things[i].se));
			mi = min(mi, things[i].se);
			++cnt;
		}
		//
		if (cnt)
		{
			if (!des.empty() && *des.begin() < things[i].fi)
				continue;
			if (mi != INF)
			{
				ans += (things[i].fi - cur) + (things[i].fi - mi);
				cur = mi;
				mi = INF;
				cnt = 0;
			}
		}
	}
	cout << ans + (M - cur);
	// 0 7 2 8
	/*
	0 7 5 3 2 8
	7 5 2 3
	5 7 3 2
	5 7 2 3
	18
	*/
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	// freopen("test.inp", "r", stdin);
	solve();
	return 0;
}
