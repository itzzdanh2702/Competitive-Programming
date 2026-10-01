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

int n;
int a[MAXN];
int b[MAXN];
int pos = 0;
int dem = 0;
int ma = -1;
bool check = 0;
int main()
{
    cin >> n;
    int tmp = a[1];
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        if (a[i] == a[1])
        {
            ++dem;
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        if (a[i] > a[i + 1])
        {
            pos = a[i];
            // check = 1;
            break;
        }
    }
    if (dem == n)
    {
        cout << "empty";
        return 0;
    }
    else
    {
        for (int i = 1; i <= n; ++i)
        {
            if (a[i] != pos)
            {
                cout << a[i] << ' ';
            }
        }
    }
}