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

int ans = 0;
int d[10];

int main(int argc, char const *argv[])
{
    FAST();
    for (int i = 1; i <= 9; ++i)
    {
        for (int i1 = 0; i1 <= 9; ++i1)
        {
            for (int i2 = 0; i2 <= 9; ++i2)
            {
                for (int i3 = 0; i3 <= 9; ++i3)
                {
                    for (int i4 = 0; i4 <= 9; ++i4)
                    {
                        for (int i5 = 0; i5 <= 9; ++i5)
                        {
                            string S;
                            int tmp = 0;
                            for (int tmp1 = 0; tmp1 <= 9; ++tmp1)
                                d[tmp1] = 0;
                            bool check = 1;
                            int cnt = 0;
                            tmp += i5 + i4 * 10 + i3 * 100 + i2 * 1000 + i1 * 10000 + i * 100000;
                            S = to_string(tmp);
                            ++d[int(S[0] - 48)]; 
                            for (int j = 1; j < S.size(); ++j)
                            {
                                if ((int(S[j] - 48) & 1) && (int(S[j - 1] - 48) & 1))
                                    ++cnt;
                                ++d[int(S[j] - 48)];
                                if (d[int(S[j] - 48)] > 1)
                                    check = 0;
                            }
                            if ((cnt >= 1) && (check))
                            {
                                ++ans;
                            }
                        }
                    }
                }
            }
        }
    }
    cout << ans;
    return 0;
}
