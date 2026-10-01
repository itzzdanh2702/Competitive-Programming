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

string S;
int n;
ll sum = 0;
int main()
{
    FAST();
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> S;
        if (S == "Tetrahedron")
        {
            sum += 4;
        }
        else if(S == "Cube")
        {
            sum += 6;
        }
        else if (S == "Octahedron")
        {
            sum += 8;
        }
        else if (S == "Dodecahedron")
        {
            sum += 12;
        }
        else if (S == "Icosahedron")
        {
            sum += 20;
        }
    }
    cout << sum;
}