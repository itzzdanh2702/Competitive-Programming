#include <bits/stdc++.h>
using namespace std;
#define oo 1000000000
void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int a[21][21];
int b[21][21];
int tmp1[21][21];
int dem = 0;
int cnt1 = 0;
int mi = oo;
bool check[21];
bool ok;
int n;

void biendoihang(int m)
{
    ++dem;
    for (int j = 1; j <= n; ++j)
    {
        if (a[m][j] == 1)
            a[m][j] = -1;
        else if (a[m][j] == -1)
            a[m][j] = 1;
    }
}

void biendoicot(int m)
{
    ++dem;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i][m] == 1)
            a[i][m] = -1;
        else if (a[i][m] == -1)
            a[i][m] = 1;
    }
    check[m] = false;
}

void biendoi()
{
    for (int i = 2; i <= n; ++i)
    {
        int cnt4 = 1;
        bool ok3[21];
        bool ok4[21];
        // lua chon 1 : bien doi hang
        for (int j = 1; j <= n; ++j)
        {
            if (a[i][j] == b[i][j] != 0)
            {
                if (check[j])
                {
                    ++cnt4;
                    for (int k = i + 1; k <= n; ++k)
                        if ((a[k][j] == b[k][j] != 0) && (!ok3[k]))
                        {
                            ok3[k] = 1;
                            ++cnt4;
                        }
                }
                else
                {
                    cnt4 = oo;
                    break;
                }
            }
        }
        // lua chon 2 : khong bien doi
        int cnt5 = 0;
        for (int j = 1; j <= n; ++j)
        {
            if (a[i][j] != b[i][j])
            {
                if (check[j] == 1)
                {
                    ++cnt5;
                    for (int k = j + 1; k <= n; ++k)
                        if ((a[k][j] == b[k][j] != 0) && (!ok4[k]))
                        {
                            ok4[k] = 1;
                            ++cnt5;
                        }
                }
                else
                {
                    cnt5 = oo;
                    break;
                }
            }
        }
        if (cnt5 < cnt4)
        {
            for (int j = 1; j <= n; ++j)
                if (a[i][j] != b[i][j])
                    if (check[j] = 1)
                        biendoicot(j);
        }
        else
        {
            biendoihang(i);
            for (int j = 1; j <= n; ++j)
                if (a[i][j] != b[i][j])
                    biendoicot(j);
        }
        for (int j = 1; j <= n; ++j)
            if (a[i][j] != 0)
                check[j] = 0;
    }
}
int main()
{
    FAST();
    memset(check, false, sizeof(check));
    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
        {
            cin >> a[i][j];
            tmp1[i][j] = a[i][j];
        }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> b[i][j];
    // lua chon 1 : khong bien doi --> neu a[i][j] != b[i][j] --> thu thuc hien bien doi cot
    for (int j = 1; j <= n; ++j)
        if (a[1][j] == 0)
            check[j] = 1;
    // lua chon 2 : bien doi hang --> neu a[i][j] == b[i][j] --> thu thuc hien bien doi
    for (int j = 1; j <= n; ++j)
        if (a[1][j] != b[1][j])
            biendoicot(j);
    biendoi();
    mi = dem;
    dem = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            a[i][j] = tmp1[i][j];
    memset(check, 0, sizeof(check));
    for (int j = 1; j <= n; ++j)
        if (a[1][j] == 0)
            check[j] = 1;
    biendoihang(1);
    for (int j = 1; j <= n; ++j)
        if (a[1][j] != b[1][j])
            biendoicot(j);
    biendoi();
    cout << min(mi, dem);
}