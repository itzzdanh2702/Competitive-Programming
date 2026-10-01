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
ll x , y;
int main()
{
    freopen("GCD2.inp","r",stdin);
    freopen("GCD2.out","w",stdout);
    cin >> TC;
    while(TC--)
    {
        cin >> x >> y;
        cout << x - __gcd(x,y) << endl;

    }
    
}
// b - b % 
