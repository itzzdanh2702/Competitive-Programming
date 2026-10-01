#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define pii pair<ll, ll>
const long long MOD = 1000000007;
#define MAXN 1000005
#define oo 1000000000
void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
int a[MAXN];
vector<int> v;
int main()
{
    v.push_back(-2);
    v.push_back(-1);
    v.push_back(0);

    cout << *lower_bound(v.begin(),v.end(),-3);
}
