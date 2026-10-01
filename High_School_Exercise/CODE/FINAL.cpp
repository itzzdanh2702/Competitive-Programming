#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nmax 1000000
int n, a[nmax];

bool check(int x)
{
	int base = 1;
	for(int i = 1; i < x; ++i)
    {
		if(a[i] + base > a[x] + n) return 0;
		else base++;
	}
	return 1;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
    freopen("FINAL.inp","r",stdin);
    freopen("FINAL.out","w",stdout);
	cin >> n;
	for(int i = 1; i <= n; ++i) cin >> a[i];
	sort(a + 1, a + n + 1, greater<int>());
	int l = 1, r = n, res = 0;
	while(l <= r)
    {
		int mid = (l + r)/2;
		if(check(mid)) res = mid, l = mid + 1;
		else r = mid - 1;
	}
	cout << res;

	return 0;
}
