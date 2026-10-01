#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define pii pair<ll, ll>
const long long MOD = 1000000007;
#define MAXN 20005
#define oo 1000000000
void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int n;
int dem = 0;
bool nt[20005];

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
    sang();
    cin >> n;
    for (int i = 1; i <= 20000; ++i)
    {
        if (!nt[i])
            continue;
        for (int j = i + 1; j <= 20000; ++j)
        {
            if (!nt[j])
                continue;
            if (1LL * pow(i, 2) * 1LL * pow(j, 2) <= n)
            {
                ++dem;
            }
        }
        if (i > 15)
            continue;
        if (1LL * pow(i, 8) <= n)
        {
            ++dem;
        }
    }
    cout << dem;
}