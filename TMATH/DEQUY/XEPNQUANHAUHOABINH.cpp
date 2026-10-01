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
int cnt = 0;
bool check[100][100];

void sinh(int k)
{
    for(int i = 1 ; i <= n ; ++i)
    {
        if(!check[k][i])
        {
            check[k][i] = true;
            for(int j = 1 ; j <= n ; ++j)
            {
                check[k][j] = true;
                check[j][k] = true;
                if((k + j <= n) and (j + 1 <= n)) 
                check[k + j][j + 1] = true;
                if((k - j >= 1) and (j + 1  <= n)) 
                check[k - j][j + 1] = true;
            }
            if(k < n)
            sinh(k + 1);
            else if (k == n) 
            {
                ++cnt;
            }
        }
    }
}
int main()
{
    FAST();
    cin >> n;
    sinh(1);
    cout << cnt;
}