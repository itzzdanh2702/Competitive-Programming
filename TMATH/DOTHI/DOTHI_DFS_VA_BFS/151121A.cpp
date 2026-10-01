#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nmax 1000000
vector<ll> ans;
ll n, tmp, tmp1;
void bfs(int val)
{
    queue<ll> qu;
    for (int i = 1; i <= 9; i++)
    {
        qu.push(i);
        ans.push_back(i);
        if (ans.size() == val)
        {
            cout << val;
            exit(0);
        }
    }
    while (!qu.empty())
    {
        ll tmp = qu.front();
        qu.pop();
        for (ll j = tmp % 10 - 1; j <= tmp % 10 + 1; j++)
        {
            if ((j >= 0) and (j <= 9) and (ans.size() <= val))
            {
                ans.push_back(tmp * 10 + j);
                qu.push(tmp * 10 + j);
            }
            else if (ans.size() > val)
            {
                return;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin.tie(0);
    cin >> n;
    bfs(n);
    cout << ans[n - 1];
}