#include <bits/stdc++.h>
using namespace std;
#define ll long long
const long long MOD = 1000000007;
#define MAXN 1000005
#define oo 1000000000
void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll TC;

int main()
{
    cin >> TC;
    while (TC--)
    {
        bool check = 0;
        ll a, b;
        cin >> a >> b;
        if ((a == 0) and (b == 0))
        {
            cout << "YES" << '\n';
        }
        else
        {
            ll l = 1, r = max(a, b);
            while (l <= r)
            {
                ll mid = (l + r) / 2;
                if (a - 2 * mid < 0)
                {
                    r = mid - 1;
                }
                else
                {
                    ll tmp = 2 * (a - 2 * mid);
                    if (tmp + mid < b)
                    {
                        r = mid - 1;
                    }
                    else if (tmp + mid == b)
                    {
                        check = 1;
                        break;
                    }
                    else
                    {
                        l = mid + 1;
                    }
                }
            }
            if (check == 1)
            {
                cout << "YES" << '\n';
                continue;
            }
            else
            {
                ll l = 1, r = max(a, b);
                while (l <= r)
                {
                    ll mid = (l + r) / 2;
                    if (a - mid < 0)
                    {
                        r = mid - 1;
                    }
                    else
                    {
                        ll tmp = a - mid;
                        if (tmp + 2 * mid < b)
                        {
                            r = mid - 1;
                        }
                        else if (tmp + 2 * mid == b)
                        {
                            check = 1;
                            break;
                        }
                        else
                        {
                            l = mid + 1;
                        }
                    }
                }
                if (check == 1)
                {
                    cout << "YES" << '\n';
                }
                else
                {
                    cout << "NO" << '\n';
                }
            }
        }
    }
}
