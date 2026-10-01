#include <bits/stdc++.h>
using namespace std;
#define ll long long
const long long MOD = 1000000007;
#define MAXN 1005
#define oo 1000000000
void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int m,k;
int pre_hang[MAXN],pre_cot[MAXN];
int a[MAXN][MAXN];

int main()
{
    FAST();
    cin >> m >> k;
    for(int i = 1 ; i <= m ; ++i)
    {
        for(int j = 1 ; j <= m ; ++j)
        {
            cin >> a[i][j];
        }
    }
    for(int i = 1 ; i <= m ; ++i)
    {
        for(int j = 1 ; j <= m ; ++j)
        {
            pre[i] += a[i][j];
        }
    }
}