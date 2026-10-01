#include <bits/stdc++.h>
using namespace std;
#define ll long long
const long long MOD = 1000000007;
#define MAXN 1000005                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        
#define oo 1000000000
void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll TC;
ll pre[MAXN];
int main()
{
    //freopen("GOOD.inp", "r", stdin);
    //freopen("GOOD.out", "w", stdout);
    cin >> TC;
    while (TC--)
    {
        memset(pre, 0, sizeof(pre));
        ll m;
        ll dem = 0;
        ll dem1 = 0;
        ll dem2 = 0;
        string S;
        string tmp;
        pre[0] = 0;
        cin >> m >> S;
        for (int i = 1; i <= m; ++i)
        {
            tmp += S;
        }
        for (int i = 0; i < tmp.size(); ++i)
        {
            if (tmp[i] == '1')
            {
                pre[i] = pre[i - 1] + 1;
            }
            else
            {                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   
                pre[i] = pre[i - 1];
            }
        }
        for (int i = 0; i < tmp.size(); ++i)
        {
           
                if (pre[tmp.size() - 1] - pre[i] == pre[i - 1])
                {
                    dem++;
                }
        
        }
        cout << dem << '\n';
    }
}
