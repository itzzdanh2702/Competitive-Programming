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
vector<int> chan, le;
int n, cnt[11], cnt1[11], remain = 0;
ll ans = 0;

int main()
{
    FAST();
    cin >> n;
    cin >> S;
    S = " " + S;
    for (int i = 1; i <= n; ++i)
    {
        if (i & 1)
        {
            le.push_back(int(S[i] - 48));
            remain += int(S[i] - 48);
        }
        else
        {
            chan.push_back(int(S[i] - 48));
            remain -= int(S[i] - 48);
        }
        remain = (remain + 11) % 11;
    }
    for (int i = 0; i < chan.size(); ++i)
    {
        int tmp1 = (remain - (11 - chan[i]) + 11) % 11;
        ans += cnt1[tmp1];
        ++cnt1[11 - chan[i]];
    }
    for (int i = 0; i < le.size(); ++i)
    {
        
        int tmp = (remain - le[i] + 11) % 11;
        ans += cnt[tmp] + cnt1[tmp];
        ++cnt[le[i]];
    }

    cout << ans;
    // quy uoc lay tong le - tong chan
}
// th 1 chan 1 le --> 
// 12111 --> 1111
//  
// 1 + 1 + 1 - 2 - 2

// 