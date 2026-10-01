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
string S;

int main()
{
    FAST();
    #ifndef ONLINE_JUDGE
    freopen("FavouriteStringofChef.inp", "r", stdin);
    freopen("FavouriteStringofChef.out", "w", stdout);
    #endif // ONLINE_JUDGE
    cin >> TC;
    while (TC--)
    {
        vector<int> type[2];
        bool check = 0;
        string P = "code";
        string Q = "chef";
        cin >> n;
        cin >> S;
        int tmp = 0;
        for (int i = 0; i < n; ++i)
        {
            if(S[i] == 'c')
            {
                if(S[i + 1] == 'o')
                {
                    type[1].push_back(i);
                }
                else if(S[i + 1] == 'h')
                {
                    type[2].push_back(i);
                }
            }
        }
        int tmp = 0;
        for(int i = 0 ; i < type[1].size() ; ++i)
        {
            if(type[1][i] < type2[tmp])
            {
                
            }
        }
    }
}