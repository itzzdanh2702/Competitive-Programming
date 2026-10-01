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

int main()
{
    FAST();
    cin >> TC;
    while(TC--)
    {
        cin >> n;
        if(n & 1)
        {
            cout << "Lihwy" << '\n';
        }
        else 
        {
            cout << "FireGhost" << '\n';
        }
    }
}