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
int a[11];
int n;
int TC;
int cnt = 0;
string ans;

void xuat()
{
    string S;
    int sum = 0;
    for (int i = 0; i <= 9; ++i)
    {
        if (a[i] == 0)
        {
            S += to_string(i);
            sum += i;
        }
    }
    if (sum == n)
    {
        ans = min(ans, S);
    }
}
void np(int k)
{
    ++cnt;
    if (cnt == 1)
    {
        ans = "";
    }
    for (int i = 0; i <= 1; ++i)
    {
        a[k] = i;
        if (k == 10)
        {
            xuat();
        }
        else if (k < 10)
        {
            np(k + 1);
        }
    }
}
int main()
{

    FAST();
    cin >> TC;
    while (TC--)
    {
        cin >> n;
        np(0);
        cout << ans << '\n';
        cnt = 0;
    }
}