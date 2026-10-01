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

int a1,b1,a2,b2; 

int main()
{
    FAST(); 
    cin >> a1 >> b1; 
    cin >> b2 >> a2; 
    if(a1 + a2 != b1 + b2)
    {
        if(a1 + a2 > b1 + b2)
            cout << "A wins";
        else 
            cout << "B wins";
    }
    else 
    {
        if(a2 > b1)
        {
            cout << "A wins";
        }
        else if (a2 < b1)
        {
            cout << "B wins";
        }
        else 
        {
            cout << "Extra time"; 
        }
    }
}