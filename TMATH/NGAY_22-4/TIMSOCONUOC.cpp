#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define pii pair<ll, ll>
const long long MOD = 1000000007;
#define MAXN 1000005
#define oo 1000000000
const ll INF = 1e18;
void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int n;
int p[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
ll mi = INF;
void backtrack(int index, ll val, ll uoc)
{
    if (uoc > n)
        return;
    if (uoc == n)
    {
        mi = min(mi, val);
    }

    for (int i = 1; i <= 63; ++i)
    {
        if (val * p[index] > mi)
        {
            break;
        }
        val *= p[index];
        backtrack(index + 1, val, uoc * (i + 1));
    }
}
int main()
{
    FAST();
    cin >> n;
    backtrack(0, 1, 1);
    cout << mi;
}