#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

struct matrix
{
    long long m[2][2];
    matrix()
    {
        memset(m, 0, sizeof(m));
    }
};

matrix operator*(matrix a, matrix b)
{
    matrix c;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                c.m[i][j] += a.m[i][k] * b.m[k][j];
                c.m[i][j] %= MOD;
            }
        }
    }
    return c;
}

matrix pow(matrix a, long long b)
{
    matrix res;
    res.m[0][0] = res.m[1][1] = 1;
    while (b > 0)
    {
        if (b % 2 == 1)
        {
            res = res * a;
        }
        a = a * a;
        b /= 2;
    }
    return res;
}

int main()
{
    long long n;
    cin >> n;
    matrix A;
    A.m[0][0] = 1;
    A.m[0][1] = 1;
    A.m[1][0] = 2;
    A.m[1][1] = 1;
    matrix An = pow(A, n - 1);
    long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        matrix A;
        if (i == 1)
        {
            ans += An.m[0][0];
        }
        else
        {
            ans += An.m[0][0] * An.m[0][0] + An.m[0][1] * An.m[1][0];
            ans %= MOD;
            An = An * A;
        }
    }
    cout << ans << endl;
    return 0;
}
