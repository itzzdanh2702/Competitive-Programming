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

int TC;
int n;
unsigned ll f[MAXN];

int main()
{
    FAST();
    f[0] = 0;
    f[1] = f[2] = 1; 
    for(int i = 3 ; i <= MAXN ; ++i)
    {
        f[i] = f[i - 1] + f[i - 2]; 
    }
    cin >> TC;
    while(TC--)
    {
        bool check = 0;
        cin >> n;
        for(int i = 0 ; i <= 51 ; ++i)
        {
            for(int j = 0 ; j <= 51 ; ++j)
            {
                if(f[i] * f[j] == n)
                {
                    cout << "YES" << '\n'; 
                    check = 1;
                    break;
                }
            }
            if(check)
            {
                break;
            }
        }
        if(!check)
        {
            cout << "NO" << '\n';
        }
    }
}