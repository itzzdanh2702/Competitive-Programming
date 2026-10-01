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

int TC;
int n;
int k;
string S[MAXN];
int a[MAXN];

int main()
{
    FAST();
    cin >> TC;
    while(TC--)
    {
        cin >> n;
        for(int i = 1 ; i <= n ; ++i)
        {
            cin >> a[i];
        }
        for(int i = 1 ; i <= n ; ++i)
        {
            cin >> k >> S[i];
        }
        for(int i = 1 ; i <= n ; ++i)
        {
            for(int j = 0 ; j < S[i].size() ; ++j)
            {
                if(S[i][j] == 'D')
                {
                    ++a[i];
                    if(a[i] == 10)
                    {
                        a[i] = 0;
                    }
                }
                else if (S[i][j] == 'U')
                {
                    --a[i];
                    if(a[i] == -1)
                    {
                        a[i] = 9;
                    }
                    else 
                    {
                        continue;
                    }
                }
            }
            cout << a[i] << ' '; 
        }
        cout << '\n';
    }
}