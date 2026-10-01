#include <bits/stdc++.h>
using namespace std;
#define ll long long
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
int f[61];

int main()
{
    FAST();
    f[0] = 1;
    cin >> n;
    for(int i = 1 ; i <= n ; ++i)
    {
        for(int j = 1 ; j <= n ; ++j)
        {
            if(j >= i)
            {
                f[j] = f[j] + f[j - i];
            }
        }
    }
    cout << f[n];
}