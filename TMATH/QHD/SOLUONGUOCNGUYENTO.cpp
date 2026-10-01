#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 1000005;

ll TC;
ll dp[MAXN];
ll f[MAXN];

void sanguoc()
{
    for(int i = 1 ; i <= MAXN ; ++i)
    {
        for(int j = i ; j <= MAXN ; j += i)
        {
            dp[j]++;
        }
    }
}

bool checknt(ll x)
{
    if(x < 2) 
    {
        return false;
    }
    for(int i = 2 ; i <= sqrt(x) ; ++i)
    {
        if(x % i == 0)
        {
            return false;
        }
    }
    return true;
}

void dungmang()
{
    for(int i = 1 ; i <= MAXN ; ++i)
    {
        f[i] = f[i - 1];
        if(checknt(dp[i]))
        {
            ++f[i];
        }
    }
}

int main()
{
    sanguoc();
    dungmang();
    cin >> TC;
    while(TC--)
    {
        ll l,r;
        cin >> l >> r;
        cout << f[r] - f[l - 1] << '\n';
    }
}