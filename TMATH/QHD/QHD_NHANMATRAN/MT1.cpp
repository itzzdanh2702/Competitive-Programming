#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
#define MAXN 1000005
#define oo 1000000000
void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

long long a[2][2], b[2][2];

int main()
{
    for (int i = 1; i <= 2; ++i)
    {
        for (int j = 1; j <= 2; ++j)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= 2; ++i)
    {
        for (int j = 1; j <= 2; ++j)
        {
            cin >> b[i][j];
        }
    }
    for (int i = 1; i <= 2; ++i)
    {
        for (int j = 1; j <= 2; ++j)
        {
            cout << a[i][j] + b[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
    for (int i = 1; i <= 2; ++i)
    {
        for (int j = 1; j <= 2; ++j)
        {
            cout << a[i][j] - b[i][j] << ' ';
        }
        cout << '\n';
    }
}