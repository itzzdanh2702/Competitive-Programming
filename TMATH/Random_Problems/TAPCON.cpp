#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
ll n,a[1000001],f[1000001],chan = 0, le = 0;

int main() {
    freopen("tapcon.inp","r",stdin);
    freopen("tapcon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++) {
		if(a[i] % 2 == 0) {
			chan = 2*chan + 1;
			chan %= mod;
			le = 2*le;
			le %= mod;
		}
		else {
			ll tmp = chan;
			chan +=  le;
			chan %= mod;
			le += tmp + 1;
			le %= mod;
		}
	}
	cout << le;
}
