#include<bits/stdc++.h>
using namespace std;
#define MAXN 2 * 10000 + 5
#define ll long long

int TC;
int n;

void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    FAST();
    cin >> TC;
    while(TC--)
    {
        cin >> n;
        for(int i = 1 ; i <= n ; ++i)
        {
            cout << i << ' ';
        }
        cout << '\n';
    }
}
