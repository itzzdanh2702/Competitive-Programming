#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define pii pair<ll, ll>
const int MOD = 1e5;
#define MAXN 10005
#define oo 1000000000
void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int TC;
int n;
ll store[MAXN];

int main()
{
    FAST();
    store[0] = 1;
    for(int i = 1 ; i <= MAXN ; ++i)
    {
        store[i] = (store[i - 1] * 2) % MOD;
        store[i] %= MOD; 
    }
    cin >> TC;
    while (TC--)
    {
        cin >> n;
        cout << store[n] - 1 << '\n';
    }
}