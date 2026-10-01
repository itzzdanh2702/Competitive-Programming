#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1000000
int n, kq[11], d[10];
int a[11], b[11];
int cnt = 0;
int cnt1 = 0;
ll ans[11];
ll ans1 = 1;
int ma = -1;
void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);    
}

void fact()
{
    ans[1] = 1;
    for (int i = 2; i <= 10; ++i)
    {
        ans[i] = i * ans[i - 1];
    }
}

struct store
{
    int old_pos, new_pos, val;
} c[MAXN];

void xuat()
{
    int S = 0;
    ++cnt1;
    for (int j = 1; j <= n; ++j)
    {
        if (kq[j] == 1)
        {
            c[j].old_pos = 1;
            c[j].new_pos = j;
            c[j].val = a[1];
        }
        else if (kq[j] == 2)
        {
            c[j].old_pos = 2;
            c[j].new_pos = j;
            c[j].val = a[2];
        }
        else if (kq[j] == 3)
        {
            c[j].old_pos = 3;
            c[j].new_pos = j;
            c[j].val = a[3];
        }
        else if (kq[j] == 4)
        {
            c[j].old_pos = 4;
            c[j].new_pos = j;
            c[j].val = a[4];
        }
        else if (kq[j] == 5)
        {
            c[j].old_pos = 5;
            c[j].new_pos = j;
            c[j].val = a[5];
        }
        else if (kq[j] == 6)
        {
            c[j].old_pos = 6;
            c[j].new_pos = j;
            c[j].val = a[6];
        }
        else if (kq[j] == 7)
        {
            c[j].old_pos = 7;
            c[j].new_pos = j;
            c[j].val = a[7];
        }
        else if (kq[j] == 8)
        {
            c[j].old_pos = 8;
            c[j].new_pos = j;
            c[j].val = a[8];
        }
        else if (kq[j] == 9)
        {
            c[j].old_pos = 9;
            c[j].new_pos = j;
            c[j].val = a[9];
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        S += c[i].val * abs(c[i].new_pos - c[i].old_pos);
        ma = max(ma, S);
    }
    if(S == 22)
    {
        for(int i = 1 ; i <= n ; ++i)
        {
            cout << c[i].old_pos << ' ' << c[i].new_pos << ' ' << c[i].val << '\n';
        } 
        cout << '\n';
    }
}
/*
6 1 1 1 5 5 

*/

void dequy(int i)
{
    for (int j = 1; j <= n; ++j)
        if (d[b[j]] > 0)
        {
            kq[i] = b[j];
            --d[b[j]];
            if (i < n)
                dequy(i + 1);
            else if (i == n)
            {
                xuat();
            }
            ++d[b[j]];
        }
}

int main()
{
    freopen("tmp.inp","r",stdin);
    freopen("tmp.out","w",stdout);
    FAST();
    // fact();
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        b[i] = i;
        ++d[b[i]];
    }
    // for(int i = 1 ; i <= cnt ; ++i)
    //{
    // ans1 *= ans[d[b[i]]];
    //}
    // cout << ans[n]/ans1 << '\n';
    dequy(1);
    cout << ma << '\n';
}
