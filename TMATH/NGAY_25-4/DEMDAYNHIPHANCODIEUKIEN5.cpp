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

char a[21];
char b[2];
int n;
int dem = 0;

void xuat()
{
    for (int i = 2; i <= n; ++i)
    {
        if ((a[i] == a[i - 1]) and (a[i - 1] == a[i - 2]))
        {
            return;
        }
    }
    for(int i = 1 ; i <= n ; ++i)
    {
        cout << a[i];
    }
    cout << '\n';
}
void quaylui(int k)
{
    for (int i = 0; i <= 1; ++i)
    {
        a[k] = b[i];
        if (k == n)
        {
            xuat();
        }
        else if (k < n)
        {
            quaylui(k + 1);
        }
    }
}
int main()
{
    FAST();
    cin >> n;
    b[0] = 'A';
    b[1] = 'B';
    quaylui(1);
}