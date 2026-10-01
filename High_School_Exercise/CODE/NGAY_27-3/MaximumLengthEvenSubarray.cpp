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

int main()
{
    FAST();
    cin >> TC;
    while(TC--)
    {
        ll sole = 0,sochan = 0;
        ll n;
        cin >> n;
        if(n % 2 == 1)
        {
            bool check = 0;
            sole += n/2 + 1;
            sochan += n/2;
            if(sole % 2 == 0)
            {
                check = 1;
            }
            else 
            {
                check = 0;
            }
            if(check == 0)
            {
                cout << n - 1 << '\n';
            }
            else 
            {
                cout << n << '\n';
            }
        }
        else 
        {
            cout << n << '\n';
        }
    }
}