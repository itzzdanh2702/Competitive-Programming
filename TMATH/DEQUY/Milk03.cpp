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

ll n;
ll a[100];
ll arr[100];
ll cnt = 0;

void xuat()
{
    ll S = 0,P = 0;
    for(int i = 1 ; i <= n ; ++i)
    {
        if(a[i] == 1)
        {
            S += arr[i];
        }
        else 
        {
            P += arr[i];
        }
    }
    if(S == P)
    {
        ++cnt;
        for(int i = 1 ; i <= n ; ++i)
        {
            cout << a[i];
        }
        cout << '\n';
    }

}

void quaylui(ll k)
{
    for(int i = 1 ; i <= 2 ; ++i)
    {
        a[k] = i;
        if(k == n)
        {
            xuat();
        }
        else 
        {
            quaylui(k + 1);
        }
    }
}
int main()
{
    FAST();
    cin >> n;
    for(int i = 1 ; i <= n ; ++i)
    {
        cin >> arr[i];
    }
    quaylui(1);
    if(cnt == 0)
    {
        cout << "-1";
    }
}