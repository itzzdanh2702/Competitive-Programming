/*************************************************

 Author :- Traverser_25
 Current Aim    :-  Reach pupil at CF
 Moto   :-  Keep going, that's only way
 
***************************************************/
#include <iostream>
#include <string>
#include <algorithm>
#include <deque>
#include <cmath>
#include <map>
#include <vector>
#include <set>
#include <queue>
#include <deque>
#define MAX INT32_MAX
#define fr(i, a, b) for (int i = a; i < b; i++)
#define ll long long int
#define pb emplace_back
#define ppb pop_back
#define all(x) x.begin(), x.end()
#define rev(x) x.rbegin(), x.rend()
#define read(x, n) fr(i, 0, n) cin >> x[i];
#define pds(x)       \
	for (auto i : x) \
		cout << i << " ";
#define endl '\n'
using namespace std;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

ll lcm(ll a, ll b)
{
	ll l = (a * b) / gcd(a, b);
	return l;
}
bool isp(int x) { return x && (!(x & (x - 1))); }
ll max(ll a, ll b) { return a > b ? a : b; }
ll min(ll a, ll b) { return a < b ? a : b; }
const int mod = 1e9 + 7;

void Traverser()
{
	//--------------------Practice_logs---------------//
	//Time:-
	//Date:-
	//Stuff:-
	//Logic:-
	//-------------------------------------------------//
	int n;
	cin >> n;
	ll cnt = 1, ans = 0;
	vector<int> v(n);
	read(v, n);
	fr(i, 1, n)
	{
		if (v[i - 1] <= v[i])
		{
			cnt++;
		}
		else
		{
			ans += (cnt * (cnt + 1) / 2);
			cnt = 1;
		}
	}

	ans += (cnt * (cnt + 1) / 2);

	cout << ans << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll TC;
	TC = 1;
	cin >> TC;
	while (TC--)
	{
		Traverser();
	}

	return 0;
}