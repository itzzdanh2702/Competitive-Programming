#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

const ll nx = 1e6 + 9;
const ll bx = 1e7 + 9;
const ll mod = 1e9 + 7;

int t;
string S;
map<string, int> mp;
vector<string> v;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    getline(cin, S);
    for (int i = 0; i < S.size(); ++i)
    {
        if (S[i] != '+')
        {
            string tmp = " ";
            ++i;
            while (S[i] != '+')
            {
                tmp += S[i];
                ++i;
            }
            v.push_back(tmp);
            tmp = " ";
        }
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size() - 1; ++i)
    {
        cout << v[i] << ' ' << "+" << ' ';
    }
    cout << v[v.size() - 1];
}