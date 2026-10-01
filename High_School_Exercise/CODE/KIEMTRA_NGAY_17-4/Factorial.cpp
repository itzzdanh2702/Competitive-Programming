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
vector<ll> v;
ll n;

int main()
{
    FAST();
    freopen("FACTORIAL.inp", "r", stdin);
    freopen("FACTORIAL.out", "w", stdout);
    cin >> n;
    cin >> S;
    for (int i = 0; i < S.size(); ++i)
    {
        if (S[i] == '2')
        {
            v.push_back(2);
        }
        else if (S[i] == '3')
        {
            v.push_back(3);
        }
        else if (S[i] == '4')
        {
            v.push_back(3);
            v.push_back(2);
            v.push_back(2);
        }
        else if (S[i] == '5')
        {
            v.push_back(5);
        }
        else if (S[i] == '6')
        {
            v.push_back(3);
            v.push_back(5);
        }
        else if (S[i] == '7')
        {
            v.push_back(7);
        }
        else if (S[i] == '8')
        {
            v.push_back(2);
            v.push_back(2);
            v.push_back(2);
            v.push_back(7);
        }
        else if (S[i] == '9')
        {
            v.push_back(2);
            v.push_back(3);
            v.push_back(3);
            v.push_back(7);
        }
    }
    sort(v.begin(), v.end(), greater<ll>());
    for (int i = 0; i < v.size(); ++i)
    {
        cout << v[i];
    }
}