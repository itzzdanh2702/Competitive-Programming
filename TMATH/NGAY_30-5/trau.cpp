#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define pii pair<ll, ll>
const long long MOD = 1000000007;
#define MAXN 10000005
#define oo 1000000000
void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
int TC;
int n;

void phantich(int k)
{
    int kq = 1;
    for (int i = 2; i <= sqrt(k); ++i)
    {
        int dem = 0;
        if (k % i == 0)
        {
            while (k % i == 0)
            {
                k /= i;
                ++dem;
            }
            kq *= dem + 1;
        }
    }
    if(k > 1)
    {
        kq *= 2;
    }
    cout << kq << '\n';
}

int main()
{
    FAST();
    cout << 10/5;
}