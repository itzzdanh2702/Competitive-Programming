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
int a[MAXN];
vector<int> positive, negative, neutral, ans;

int main()
{
    FAST();
    cin >> TC;
    while (TC--)
    {
        positive.clear();
        neutral.clear();
        negative.clear();
        ans.clear();
        ll sum = 0;
        cin >> n;
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i];
            if (a[i] > 0)
                positive.push_back(a[i]);
            else if (a[i] < 0)
                negative.push_back(a[i]);
            else
                neutral.push_back(a[i]);
        }
        if (neutral.size() == n)
        {
            cout << "NO" << '\n';
            continue;
        }
        else
        {
            cout << "YES" << '\n';
            sort(positive.begin(), positive.end());
            sort(negative.begin(), negative.end());
            for (auto x : neutral)
            {
                cout << x << ' ';
            }
            for (int i = 0; i < positive.size(); ++i)
            {
                if (i == 0)
                {
                    ans.push_back(positive[i]);
                    sum += positive[i];
                }
                else
                {
                    if ((sum > 0) && (negative.size() > 0))
                    {
                        ans.push_back(negative[negative.size() - 1]);
                        sum += negative[negative.size() - 1];
                        negative.pop_back();
                        --i;
                        continue;
                    }
                    else if (sum <= 0)
                    {
                        ans.push_back(positive[i]);
                        sum += positive[i];
                        continue;
                    }
                    ans.push_back(positive[i]);
                }
            }
            if (ans.size() < n)
            {
                for (int i = 0; i < negative.size(); ++i)
                {
                    ans.push_back(negative[i]);
                }
            }
            for (auto x : ans)
            {
                cout << x << ' ';
            }
            cout << '\n';
        }
    }
}