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

int a, b, x, y;
int cnt = 0;

int main()
{
    FAST();
    cin >> a >> b >> x >> y;
    while(a != b)
    {
        if(a == b)
        {
            cout << cnt;
            return 0;
        }
        if(a > b)
        {
            cout << 0; 
            return 0; 
        }
        if(a != b)
        {
            a += x;
            ++cnt;
        }
        if(a == b)
        {
            cout << cnt;
            return 0;
        }
        if(a > b)
        {
            cout << 0; 
            return 0;
        }
        if(a != b)
        {
            b -= y;
            ++cnt;
        }
        if(a == b)
        {
            cout << cnt; 
            return 0;
        }
        if(a > b)
        {
            cout << 0;
            return 0; 
        }
    }
}