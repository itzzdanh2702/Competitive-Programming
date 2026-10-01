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

int a[20];
int n, m;
string ans = "000000000000000000000000";
string S, T;

void xuat()
{
    bool check = 1;
    string P;
    int cnt = 0, cnt1 = 0;
    for (int i = 1; i <= n + m; ++i)
    {
        if (a[i] & 1)
        {
            if (cnt1 + 1 > m)
            {
                check = 0;
                break;
            }
            P += T[++cnt1];
        }
        else
        {
            if (cnt + 1 > n)
            {
                check = 0;
                break;
            }
            P += S[++cnt];
        }
    }
    if ((check) && (P[0] != '0'))
        ans = max(ans, P);
    // if ((check) )
    // {
    //     ans = min(ans, P);
    // }
}
void np(int k)
{
    for (int i = 0; i <= 1; ++i)
    {
        a[k] = i;
        if (k < n + m)
        {
            np(k + 1);
        }
        else if (k == n + m)
        {
            xuat();
        }
    }
}
int main()
{
    FAST();
    cin >> S >> T;
    n = S.size();
    m = T.size();
    S = " " + S;
    T = " " + T;
    np(1);
    cout << ans;
}