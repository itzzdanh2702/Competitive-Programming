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

ll TC;
ll a[1001][1001];
ll dp[1001][1001][1];
int main()
{
    cin >> TC;
    while(TC--)
    {
        ll N,M;
        cin >> N >> M;
        for(int i = 1 ; i <= N ; ++i)
        {
            for(int j = 1 ; j <= M ; ++j)
            {
                cin >> a[i][j];
            }
        }
        
    }
}
