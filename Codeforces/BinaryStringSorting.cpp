#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define pii pair<ll, ll>
const long long MOD = 1000000007;
const ll oo = 1e12;
const ll MAX_VAL = 1e18;
#define MAXN 1000005

void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int TC;
string S;

int main()
{
    FAST();
    cin >> TC;
    while (TC--)
    {
        ll mi = MAX_VAL;
        ll cnt0 = 0, cnt1 = 0;
        cin >> S;
        for (int i = 0; i < S.size(); ++i)
        {
            if (S[i] == '1')
            {
                ++cnt1;
            }
        }
        for (int i = 0; i < S.size(); ++i)
        {
            if (S[i] == '0')
            {
                ++cnt0;
            }
            else
            {
                --cnt1;
            }
            ll length1 = cnt0 + cnt1 + (S[i] == '1') + (S[i + 1] == '0');
            ll price = (S.size() - length1) * (oo + 1);
            if ((S[i] == '1') and (S[i + 1] == '0'))
            {
                price += oo;
            }
            mi = min(mi, price);
        }
        cout << mi << '\n';
    }
}