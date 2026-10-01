#include <bits/stdc++.h>
using namespace std;
#define ll long long
const long long MOD = 1000000007;
#define MAXN 100005
#define oo 1000000000
void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int TC;
int n, m;
int a[MAXN];
int b[MAXN];
int near_left[MAXN], near_right[MAXN];

int main()
{
    FAST();
    cin >> TC;
    while (TC--)
    {
        int pos1 = 0, pos2 = 0;
        cin >> n >> m;
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i];
        }
        for (int i = 1; i <= m; ++i)
        {
            cin >> b[i];
        }
        for (int i = 1; i <= n; ++i)
        {
            if (a[i] == 1)
            {
                near_left[i] = pos1;
                pos1 = i;
            }
            else
            {
                near_left[i] = pos1;
            }
        }
        for (int i = n; i >= 1; --i)
        {
            if (a[i] == 2)
            {
                near_right[i] = pos2;
                pos2 = i;
            }
            else
            {
                near_right[i] = pos2;
            }
        }
        for (int i = 1; i <= m; ++i)
        {
            if(b[i] == 1)
            {
                cout << "0" << ' ';
                continue;
            }
            if (a[b[i]] > 0)
            {
                cout << "0" << ' ';
                continue;
            }
            else
            {
                if ((near_left[b[i]] == 0) and (near_right[b[i]] != 0))
                {
                    cout << near_right[b[i]] - b[i] << ' ';
                }
                else if ((near_left[b[i]] != 0) and (near_right[b[i]] == 0))
                {
                    cout << b[i] - near_left[b[i]] << ' ';
                }
                else if ((near_left[b[i]] == 0) and (near_right[b[i]] == 0))
                {
                    cout << -1 << ' ';
                }
                else if ((near_left[b[i]] != 0) and (near_right[b[i]] != 0))
                {
                    cout << min(near_right[b[i]] - b[i], b[i] - near_left[b[i]]) << ' ';
                }
                continue;
            }
        }
        cout << '\n';
    }
}
/*
15 15 
0 0 0 0 0 0 1 2 1 1 1 1 0 1 1
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
output:
dung:
0 6 5 4 3 2 0 0 0 0 0 0 1 0 0 
sai:
7 6 5 4 3 2 0 0 0 0 0 0 1 0 0 
*/