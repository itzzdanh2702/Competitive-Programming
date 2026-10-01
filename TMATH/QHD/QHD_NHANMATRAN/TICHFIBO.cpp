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

unsigned ll store[MAXN];
ll TC;

void fib()
{
    store[0] = store[1] = 1;
    for (int i = 2; i <= 92; ++i)
    {
        store[i] = store[i - 1] + store[i - 2];
    }
}

int main()
{
    FAST();
    fib();
    cin >> TC;
    while(TC--)
    {
        bool check = 0;
        unsigned ll n;
        cin >> n;
        for(int i = 1 ; i <= 50 ; ++i)
        {
            for(int j = 1 ; j <= 50 ; ++j)
            {
                if(store[i] * store[j] == n)
                {
                    check = 1;
                    break;
                }
            }
        }
        if(check == 1)
        {
            cout << "YES" << '\n';
        }
        else 
        {
            cout << "NO" << '\n';
        }
    }
}