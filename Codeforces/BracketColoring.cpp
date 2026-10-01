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
int ans[MAXN], ans1[MAXN];
string S;
bool check1[MAXN], check2[MAXN], check3[MAXN], check4[MAXN];

bool check_bracket(string Q, bool check[])
{
    int cnt = 0;
    stack<int> st;
    for (int i = 0; i < Q.size(); ++i)
    {
        if (Q[i] == '(')
        {
            st.push(i);
            continue;
        }
        if (!st.empty())
        {
            check[st.top()] = 1;
            check[i] = 1;
            st.pop();
            ++cnt;
        }
    }
    if (cnt * 2 == Q.size())
        return true;
    return false;
}
void solve(string Q)
{
    string P, tmp1, tmp2;
    for (int i = 0; i < Q.size(); ++i)
    {
        check1[i] = 0;
        check2[i] = 0;
        check3[i] = 0;
        check4[i] = 0;
    }
    if (Q.size() & 1)
    {
        cout << "-1" << '\n';
        return;
    }
    if (check_bracket(Q, check1))
    {
        cout << 1 << '\n';
        for (int i = 0; i < Q.size(); ++i)
        {
            cout << 1 << ' ';
        }
        cout << '\n';
        return;
    }
    P = Q;
    reverse(Q.begin(), Q.end());
    if (check_bracket(Q, check2))
    {
        cout << 1 << '\n';
        for (int i = 0; i < Q.size(); ++i)
        {
            cout << 1 << ' ';
        }
        cout << '\n';
        return;
    }
    for (int i = P.size() - 1; i >= 0; --i)
        if (!check1[i])
        {
            tmp1 += P[i];
            ans[i] = 2;
        }
        else
        {
            ans[i] = 1;
        }
    if (check_bracket(tmp1, check3))
    {
        cout << 2 << '\n';
        for (int i = 0; i < P.size(); ++i)
        {
            cout << ans[i] << ' ';
            ans[i] = 0;
        }
        cout << '\n';
        return;
    }
    for (int i = Q.size() - 1; i >= 0; --i)
        if (!check2[i])
        {
            tmp2 += Q[i];
            ans1[i] = 2;
        }
        else
        {
            ans1[i] = 1;
        }
    if (check_bracket(tmp2, check4))
    {
        cout << 2 << '\n';
        for (int i = 0; i < Q.size(); ++i)
        {
            cout << ans1[i] << ' ';
            ans1[i] = 0;
        }
        cout << '\n';
        return;
    }
    cout << "-1" << '\n';
}
int main(int argc, char const *argv[])
{
    FAST();
    cin >> TC;
    while (TC--)
    {
        cin >> n;
        cin >> S;
        solve(S);
    }
    return 0;
}

//)))((()(())))()((
//