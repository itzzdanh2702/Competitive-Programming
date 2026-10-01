#include <bits/stdc++.h>

 
const int ar = 1e6+9;
 
using namespace std;
 
string s;
int n, pre[ar][26], sum[ar], f[ar], res = 1;
 
void sub123() 
{
    for(int i = 1; i <= n; ++i)
        for(char c = 'a'; c <= 'z'; ++c)
            pre[i][c - 'a'] = pre[i - 1][c - 'a'] + (c == s[i]);
 
    for(int i = 1; i <= n; ++i)
        for(int j = i; j <= n; ++j) 
            for(char c = 'a'; c <= 'z'; ++c)
                if(pre[j][c - 'a'] - pre[i - 1][c - 'a'] > (j - i + 1) / 2)
                res = max(res, j - i + 1);
    cout << res;
}
 
void sub4() 
{
    for(char c = 'a'; c <= 'z'; ++c) 
    {
        memset(sum, 0, sizeof sum);
        memset(f, 0x3f, sizeof f);
        for(int i = 1; i <= n; ++i) 
        {
            if(c == s[i])
            {
                sum[i] = sum[i - 1] + 1;
            }
            else 
            {
                sum[i] = sum[i - 1] - 1;
            }
            //f[i] = min(f[i - 1], sum[i]);
        }
 
        for(int i = 1; i <= n; ++i) 
        {
            int l = 1, r = i, pos = i;
            while(l <= r) 
            {
                int mid = (l + r)/2;
                if(sum[i] - sum[mid - 1] > 0) 
                    pos = mid, r = mid - 1;
                else l = mid + 1;
            }
            res = max(res, i - pos + 1);
        }
    }
    cout << res;
}
 
int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    //freopen("matdo.inp", "r", stdin);
    //freopen("matdo.out", "w", stdout);
    cin >> s;
	n = s.size();
	s = ' ' + s;
 
    if(n <= 2000) sub123();
    else sub4();
 
    return 0;
}
 
 