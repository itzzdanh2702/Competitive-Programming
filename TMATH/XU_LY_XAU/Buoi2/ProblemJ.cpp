#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define pii pair<ll, ll>
const long long MOD = 1000000007;
#define MAXN 2 * 100005
#define oo 1000000000
void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int n;
int d_odd[MAXN];
int d_even[MAXN];
int ans = 0;
string S;

void odd_padlinmore(string S)
{
    int l = 1, r = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (i > r)
        {
            d_odd[i] = 0;
        }
        else
        {
            d_odd[i] = min(r - i, d_odd[l + (r - i)]);
        }
        while ((i - d_odd[i] - 1 >= 1) && (i + d_odd[i] + 1 <= n) && (S[i - d_odd[i] - 1] == S[i + d_odd[i] + 1]))
        {
            ++d_odd[i];
        }
        if (i + d_odd[i] > r)
        {
            l = i - d_odd[i];
            r = i + d_odd[i];
        }
    }
}

void even_padlinmore(string S)
{
    int l = 1, r = 0;
    for (int i = 1; i < n; ++i)
    {
        int j = i + 1;
        if (j > r)
        {
            d_even[i] = 0;
        }
        else
        {
            d_even[i] = min(r - j + 1, d_even[l + (r - j)]);
        }
        while ((i - d_even[i] >= 1) && (j + d_even[i] <= n) && (S[i - d_even[i]] == S[j + d_even[i]]))
        {
            ++d_even[i];
        }
        if (i + d_even[i] > r)
        {
            l = j - d_even[i];
            r = i + d_even[i];
        }
    }
}

int main()
{
    FAST();
    cin >> n;
    cin >> S;
    S = " " + S;
    odd_padlinmore(S);
    even_padlinmore(S);
    for (int i = 1; i <= n; ++i)
    {
        ans += d_odd[i] + 1 + d_even[i];
    }
    cout << ans;
}