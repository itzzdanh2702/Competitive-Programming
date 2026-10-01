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

int TC;
int n;

int main()
{
    FAST();
    cin >> TC;
    while(TC--)
    {
        ll S = 0;
        cin >> n;
        ll m = n;
        while(n--)
        {
            S += 2 * n;
        }
        if(m % 1 == 0)
        {
            cout << S << '\n';
        }
        else 
        {
            cout << S - 1 << '\n';
        }

      
    }
}