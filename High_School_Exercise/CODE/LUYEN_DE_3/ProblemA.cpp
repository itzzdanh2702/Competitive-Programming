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

int n;
string T;
ll S = 0;

ll get(int n)
{
    ll P = n;
    vector<int> v;
    while (n > 0)
    {
        v.push_back(n % 10);
        n /= 10;
    }
    reverse(v.begin(),v.end()); 
    for(auto x : v)
    {
        P *= 10; 
        P += x;
    }
    return P; 
}

int main()
{
    FAST();
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        S += get(i); 
    }
    cout << S; 
}