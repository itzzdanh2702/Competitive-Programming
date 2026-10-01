#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
#define MAXN 1000005
#define oo 1000000000


void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

long long m,n,p;
long long a[101][101], b[101][101];

int main()
{
    FAST(); 
    cin >> m >> n >> p;
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= p; ++j)
        {
            cin >> b[i][j];
        }
    }
    for(int i = 1 ; i <= m ; ++i)
    {
        for(int j = 1 ; j <= p ; ++j)
        {
            int sum = 0;
            for(int k = 1 ; k <= m ; ++k)
            {
                sum += a[i][k] * b[k][j];
            }
            cout << sum << ' ';
        }
        cout << '\n';
    
    }
}