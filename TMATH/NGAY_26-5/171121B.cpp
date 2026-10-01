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

int n;
int a[MAXN];
int dem = 0;
int kq[MAXN];
bool check[MAXN];

struct store
{
    int val, pos;
} b[MAXN];
int main()
{
    FAST();
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        b[i].val = a[i];
        b[i].pos = i;
    }
    int l = 1, r = n;
    while ((l >= 1) && (r <= n))
    {
        int ma = -1;
        int ma1 = -1;
        int ma2 = -1;
        int ma3 = -1;
        int pos = 0;
        int pos1 = 0;
        int tmp1 = 0;
        int tmp2 = 0;
        ++dem;
        if (dem == n + 1)
        {
            break;
        }
        if (dem % 2 == 1)
        {
            for (int i = 1; i <= n; ++i)
            {
                if (!check[i])
                {
                    if (b[i].val * abs(b[i].pos - l) > ma)
                    {
                        ma = b[i].val * abs(b[i].pos - l);
                        pos = i; // GT lon nhat
                    }
                }
            }
            for (int i = 1; i <= n; ++i)
            {
                if (!check[i])
                {
                    if (i != pos)
                    {
                        if (b[i].val * abs(b[i].pos - l) > ma1)
                        {
                            ma1 = b[i].val * abs(b[i].pos - l);
                            pos1 = i; // GT lon nhi
                        }
                    }
                }
            }

            // Thu Dien GTL nhi vao o le
            ma2 = max(b[pos1].val * abs(r - pos1), b[pos1].val * abs(l + 1 - pos1));
            tmp1 = ma + ma2;
            // Dien GTL nhat vao o le
            ma3 = max(b[pos].val * abs(r - pos), b[pos].val * abs(l + 1 - pos));
            tmp2 = ma1 + ma3;    
            
            if (tmp1 >= tmp2)
            {
                kq[l] = b[pos].val;
                check[pos] = 1;
                ++l;
            }
            else
            {
                kq[l] = b[pos1].val;
                check[pos1] = 1;
                ++l;
            }
        }
        else
        {
            for (int i = 1; i <= n; ++i)
            {
                if (!check[i])
                {
                    if (b[i].val * abs(b[i].pos - r) > ma)
                    {
                        ma = b[i].val * abs(b[i].pos - r);
                        pos = i; // GT lon nhat
                    }
                }
            }
            for (int i = 1; i <= n; ++i)
            {
                if (!check[i])
                {
                    if (i != pos)
                    {
                        if (b[i].val * abs(b[i].pos - r) > ma1)
                        {
                            ma1 = b[i].val * abs(b[i].pos - r);
                            pos1 = i; // GT lon nhi
                        }
                    }
                }
            }
            // 4  _ _ 3 hoac 1
            // if (dem == 2)
            // {
            //     cout << ma << ' ' << ma1 << '\n';
            //     cout << pos << ' ' << pos1;
            //     return 0;
            // }
            // Thu Dien GTL nhi vao o le
            ma2 = max(b[pos1].val * abs(l - pos1), b[pos1].val * abs(r - 1 - pos1));
            tmp1 = ma + ma2;
            // Dien GTL nhat vao o le
            ma3 = max(b[pos].val * abs(l - pos), b[pos].val * abs(r - 1 - pos));
            tmp2 = ma1 + ma3;
            if (tmp1 >= tmp2)
            {
                kq[r] = b[pos].val;
                check[pos] = 1;
            }
            else
            {
                kq[r] = b[pos1].val;
                check[pos1] = 1;
            }
            --r;
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        cout << kq[i] << ' ';
    }
}