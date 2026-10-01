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

int TC, even[MAXN];

int kq(int p)
{
    int S = 0;
    while (p > 0)
    {
        S += p % 10;
        p /= 10;
    }
    return S;
}

int main()
{
    freopen("B.INP","r",stdin); 
    freopen("B.OUT","w",stdout);
    FAST();
    for (int i = 1; i <= 1e6; ++i)
    {
        if (kq(i) & 1)
        {
            even[i] = even[i - 1];
        }
        else
        {
            even[i] = even[i - 1] + 1;
        }
    }

    cin >> TC;
    while (TC--)
    {
        int a, b;
        cin >> a >> b;
        cout << even[b] - even[a - 1] << '\n'; 
    }
}