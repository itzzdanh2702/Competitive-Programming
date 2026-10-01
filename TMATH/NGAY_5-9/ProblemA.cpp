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

int S = 0;
int a, b;
ll ans = 0;

int chuso(int n)
{
    int dem = 0;
    while (n > 0)
    {
        ++dem;
        n /= 10;
    }
    return dem;
}

int tong(int n)
{
    int S = 0;
    while (n > 0)
    {
        S += n % 10;
        n /= 10;
    }
    return S;
}

int main()
{
    FAST();
    cin >> a >> b;
    for (int i = a; i <= b; ++i)
    {
        bool check = 0;
        int tmp = i;
        while (!check)
        {
            int dem = 0;
            if (chuso(tmp) == 1)
            {
                check = 1;
                ans += tong(tmp); 
            }
            else 
            {
                tmp = tong(tmp); 
            }
        }
    }
    cout << ans;
}