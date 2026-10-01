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

string S, T;
int n, m;
vector<char> ans;

int main(int argc, char const *argv[])
{
    FAST();
    cin >> S >> T;
    n = S.size();
    m = T.size();
    S = " " + S;
    T = " " + T;
    int i = 1, j = 1;
    while (i <= n || j <= m)
    {
        if (S[i] > T[j])
        {
            ans.push_back(S[i]);
            ++i;
        }
        else if (S[i] < T[j])
        {
            ans.push_back(T[j]); 
            ++j;
        }
        else 
        {
            int tmp_i = i;
            int tmp_j = j;
            while((S[tmp_i] == T[tmp_j]) && (tmp_i <= n) && (tmp_j <= m))
            {
                ans.push_back(S[tmp_i]); 
                ++tmp_i;
                ++tmp_j; 
            }
            cout << tmp_i << ' ' << tmp_j;
            break;
            if((tmp_i > n) || (tmp_j > m)) 
            {
                if(tmp_i > n)
                {
                    j = tmp_j;
                }
                else 
                {
                    i = tmp_i; 
                }
                break; 
            }
            if(S[tmp_i] > T[tmp_j])
            {   
                i = tmp_i + 1; 
            }
            else
            {
                j = tmp_j + 1; 
            }
        }
    }
    // for(auto x : ans) cout << x;
    // for(int it = i ; it <= n ; ++it) cout << S[it];
    // for(int it = j ; it <= m ; ++it) cout << T[it]; 

    return 0;
}