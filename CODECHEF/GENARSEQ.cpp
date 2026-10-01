#include <bits/stdc++.h>
using namespace std;
#define MAXN 1005
#define oo 100000
void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int TC;
int a, b, n;

int main()
{
    FAST();
    cin >> TC;
    while (TC--)
    {
        cin >> a >> b >> n;
        vector<int> check(1e7+10,0);
        vector<int> x(n + 1,0);
        x[1] = 1;
        cout << x[1] << ' ';
        int tmp = a * x[1] - b * x[1];
        if (tmp > 0)
            check[tmp] = 1;
        for (int k = 1; k <= MAXN; ++k)
        {
            if (!check[x[1] + k])
            {
                x[2] = x[1] + k;
                cout << x[1] + k << ' ';
                break;
            }
        }
        for (int i = 3; i <= n; ++i)
        {
            for (int j = 1; j <= i - 1; ++j)
            {
                int tmp1 = a * x[j] - b * x[i - 1];
                if (tmp1 > 0)
                    check[tmp1] = 1;
                // int tmp2 = b * x[j] - a * x[i - 1];
                // if (tmp2 > 0)
                //     check[tmp2] = 1;
                // int tmp3 = b * x[i - 1] - a * x[j];
                // if (tmp3 > 0)
                //     check[tmp3] = 1;
                int tmp4 = a * x[i - 1] - b * x[j];
                if (tmp4 > 0)
                    check[tmp4] = 1;
            }

            for (int k = 1; k <= 10000010; ++k)
            {
                if (!check[x[i - 1] + k])
                {
                    x[i] = x[i - 1] + k;
                    cout << x[i - 1] + k << ' ';
                    break;
                }
            }
        }
        cout << '\n';
    }
}