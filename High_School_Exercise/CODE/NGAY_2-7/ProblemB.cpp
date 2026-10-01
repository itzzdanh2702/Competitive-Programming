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

int cnt = 0;
string S, P, Q, K;
bool check[MAXN];
char a;

int main()
{
    freopen("giaima.inp","r",stdin);
    freopen("giaima.out","w",stdout);
    FAST();
    cin >> S;
    Q = S;
    cin >> a;
    for (int i = 0; i < S.size(); ++i)
    {
        if (S[i] != a)
            K += S[i];
    }
    if (K.size() & 1)
        return cout << -1, 0;
    string P = K.substr(K.size()/2);
    if(P == Q.substr(Q.size() - P.size()))
    {
        for(int i = 0 ; i < Q.size() - P.size() ; ++i)
            cout << Q[i]; 
    }
    else
        cout << -1;
    // abcab
}
