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
ll n;

int main()
{
    cin >> TC;
    while (TC--)
    {
        ll N, M;
        cin >> N >> M;
        if (M % 2 == 1)
        {
            if (N % 2 == 1)
                cout << (N / 2 + 1) * (M / 2 + 1) << '\n';
            else
                cout << (N / 2) * (M / 2 + 1) << '\n';
        }
        else
        {
            if (N % 2 == 0)
                cout << (N / 2) * (M / 2) << '\n';
            else
                cout << (N / 2 + 1) * (M / 2) << '\n';
        }
    }
}
