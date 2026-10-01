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
// void sang()
// {
//     for (int i = 1; i <= MAXN; i++)
//         nt[i] = true;
//     nt[0] = nt[1] = false;

//     for (int i = 2; i * i <= MAXN; i++)
//     {
//         if (nt[i])
//         {
//             for (int j = i * i; j <= MAXN; j += i)
//                 nt[j] = false;
//         }
//     }
// }
int main()
{
    FAST();
    ll n;
    cin >> n;
    ll dem;
    ll P = 0, Q = 0;
    for (int i = 2; i <= sqrt(n); i++)
    {
        dem = 0;
        while (n % i == 0)
        {
            ++dem;
            n /= i;
        }
        if (dem)
        {
            if (dem % 2 == 0)
            {
                P += dem;
            }
            else
            {
                Q += dem;
            }
        }
    }
    if (n > 1)
    {
        Q += 1;
    }
    cout << P << ' ' << Q;
}