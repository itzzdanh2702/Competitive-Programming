#include <bits/stdc++.h>
using namespace std;
#define ll long long
const long long MOD = 1000000007;
#define MAXN 10000005
#define oo 1000000000
void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll n, i = 2, dem = 0, k;
ll pre_kq;
set<ll> ans;
bool check[MAXN];
int main()
{
    FAST();
    cin >> n >> k;
    ll tmp = n;
    while (n > 1)
    {
        if (n % i == 0)
        {
            n = n / i;
            ans.insert(i);
        }
        else
        {
            i++;
        }
    }
    ll dem = 0;
    for(auto x : ans)
    {
        ll tmp1 = tmp;
        while(tmp1 > 0)
        {
            if(!check[tmp1])
            {
                ++dem;
            }
            tmp1 -= x;
        }
    }
    
}
// 2 4 6 8 10 
// 3 9

// 1 5 7 11

// 2 4 6 8 
// 5