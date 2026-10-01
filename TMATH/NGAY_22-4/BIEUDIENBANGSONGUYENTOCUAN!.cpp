#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define pii pair<ll, ll>
const long long MOD = 1000000007;
#define MAXN 1005
#define oo 1000000000
void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

bool nt[MAXN];
int n;
void sang()
{
    for (int i = 1; i <= MAXN; i++)
        nt[i] = true;
    nt[0] = nt[1] = false;

    for (int i = 2; i * i <= MAXN; i++)
    {
        if (nt[i])
        {
            for (int j = i * i; j <= MAXN; j += i)
                nt[j] = false;
        }
    }
}

int main()
{
    FAST();
    memset(nt, true, sizeof(nt));
    sang();
    while (cin >> n)
    {
        for (int i = 2; i <= n; ++i)
        {
            int tmp1 = n;
            if (nt[i])
            {
                int tmp = 0;
                while (tmp1 > 0)
                {
                    tmp += tmp1 / i;
                    tmp1 /= i;
                }
                cout << tmp << ' ';
            }
        }
        cout << '\n';
    }
}